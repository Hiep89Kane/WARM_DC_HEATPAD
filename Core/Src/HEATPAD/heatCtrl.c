#include "myHeader.h"

OUTPUT_t _ctrlOutput[_MAX_OUTPUT];
button_t HW_Button;
uint16_t hw_AdcArr[_adcTotal];
Epprom_str _eppConfig;
uint8_t heatPower;

timer_virtual_t _timer_updateLCD,_timer_runHeater,_timer_timeout;
char LcdStr_row[_USER_TEXT_LCD_NUM_ROW][_STRING_BUFFER_SIZE];

void getPower();
void getPower(){
  heatPower = (uint8_t)(hw_AdcArr[_adcVaristor]/20);
  if(heatPower<5)heatPower=0;
  else if(heatPower>95)heatPower=100;
}

void HW_HEAT_dimerCtrl(uint8_t percent);
void HW_HEAT_dimerCtrl(uint8_t percent){
  (percent >=100) ?  HEAT_pwmSetCompare(HARDWARE_TIM_PWM_HEAT_PERIOD+1) : HEAT_pwmSetCompare(percent*HARDWARE_TIM_PWM_HEAT_PERIOD/100);
}

//Relay controls the autofill solenoid
void HW_RLSOL_BaseCtrl(uint8_t ON_OFF){
  if(ON_OFF) RLSOL_ON;
  else RLSOL_OFF;
}


/*Functions*/
void updateLcd(){
  static char str_cmp0[_STRING_BUFFER_SIZE],
	      str_cmp1[_STRING_BUFFER_SIZE];
  uint8_t result1, result2;

  if(!timer_expired(&_timer_updateLCD))
    return;
  timer_set(&_timer_updateLCD, 250);
  getPower();

  //Nếu chuỗi không thay đổi thì return
  result1 = memcmp(LcdStr_row[0], str_cmp0, _STRING_BUFFER_SIZE);
  result2 = memcmp(LcdStr_row[1], str_cmp1, _STRING_BUFFER_SIZE);
  if(result1 == 0 && result2==0)return;

  //Cập nhật dữ liệu mới lên LCD
  //CLCD_I2C_Clear(&LCD1);
  ShowLCD_String(LcdStr_row[0], 0, 0);
  ShowLCD_String(LcdStr_row[1], 0, 1);

  memcpy(str_cmp0, LcdStr_row[0], _STRING_BUFFER_SIZE);
  memcpy(str_cmp1, LcdStr_row[1], _STRING_BUFFER_SIZE);
}

void heatCtrl_1msIrqHandle(){
  static uint8_t tx10;

  //Outputs
  for(uint8_t i=0; i<_MAX_OUTPUT; i++)
      OUTPUT_blinkHandle(&_ctrlOutput[i]);

  /*10ms check poll*/
  if(++tx10 >= 10){
     tx10 = 0;
     timer_periodic_poll();
     btn_progress_loop(&HW_Button,BUTTON_PinStt);
  }
}

void heatCtrlInit(){

  HAL_TIM_PWM_Start(&HARDWARE_TIM_PWM_HEAT, HARDWARE_TIM_PWM_HEAT_CHANNEL);
  HEAT_pwmSetCompare(0);

  HAL_ADCEx_Calibration_Start(&hadc);
  HAL_ADC_Start_DMA(&hadc, (uint32_t *)hw_AdcArr, _adcTotal);
  //setCalibration_16V_400mA();
  /*Init i2c2 for LCD and Ina219 */
  HAL_I2C_Init(&_USER_DEFINE_I2C_LCD);
  CLCD_I2C_Init(&LCD1, &_USER_DEFINE_I2C_LCD, 0x4e, 20, 4);

  //HW_Button.cb_function = &callback_btnConfigHandle;

  /*Init Outputs Control*/
  OUTPUT_configInit(&_ctrlOutput[_RLHEAT], HW_RLSOL_BaseCtrl, 0);
  OUTPUT_setOn(&_ctrlOutput[_RLHEAT],0);

  //Load flash data
  flash_init_address(&_eppConfig.eppStart, &_eppConfig.eppEnd);
  flash_read();

  ShowLCD_String("   HEAT WARM", 0, 0);
  ShowLCD_String(" Giu Am On Noi", 0, 1);

  timer_set(&_timer_updateLCD, 250);
  timer_set(&_timer_runHeater, 1000);
}

void heatCtrlLoop(){
  static uint16_t cntSec=0;
  flash_update();
  updateLcd();

  if(timer_expired(&_timer_runHeater)){
      timer_restart(&_timer_runHeater);
      if(heatPower > 0)sprintf(LcdStr_row[0],"ON");
      else sprintf(LcdStr_row[0],"OFF");
      sprintf(LcdStr_row[1],"CS=%3u ThoiGian",heatPower);
      HW_HEAT_dimerCtrl(heatPower);
      if(++cntSec > (8*3600)){
	  HW_HEAT_dimerCtrl(0);
	  OUTPUT_setOff(&_ctrlOutput[_RLHEAT],0);
	  timer_stop(&_timer_runHeater);
      }
  }
}


