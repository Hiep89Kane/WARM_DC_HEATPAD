#include "myHeader.h"

//#ifdef _INTERVAL_TICK  /*10 ms*/
//#undef _INTERVAL_TICK
//#define _INTERVAL_TICK 10
//#endif

//redefine for text LCD 16x2
#ifdef _USER_TEXT_LCD_NUM_COL
#undef _USER_TEXT_LCD_NUM_COL
#define _USER_TEXT_LCD_NUM_COL	16
#endif

#ifdef _USER_TEXT_LCD_NUM_ROW
#undef _USER_TEXT_LCD_NUM_ROW
#define _USER_TEXT_LCD_NUM_ROW	2
#endif

#define _STRING_BUFFER_SIZE	_USER_TEXT_LCD_NUM_COL+1

#define HARDWARE_TIM_PWM_HEAT		htim15
#define HARDWARE_TIM_PWM_HEAT_CHANNEL	TIM_CHANNEL_2
#define HARDWARE_TIM_PWM_HEAT_PERIOD	HARDWARE_TIM_PWM_HEAT.Init.Period
#define HEAT_pwmSetCompare(cmp)		__HAL_TIM_SET_COMPARE(&HARDWARE_TIM_PWM_HEAT, HARDWARE_TIM_PWM_HEAT_CHANNEL, cmp)

#define RLSOL_ON 			HAL_GPIO_WritePin(RLSOL_GPIO_Port, RLSOL_Pin, 1)
#define RLSOL_OFF 			HAL_GPIO_WritePin(RLSOL_GPIO_Port, RLSOL_Pin, 0)
#define RLSOL_TOG 			HAL_GPIO_TogglePin(RLSOL_GPIO_Port, RLSOL_Pin)
#define RLSOL_STT 			!HAL_GPIO_ReadPin(RLSOL_GPIO_Port, RLSOL_Pin)
#define BUTTON_PinStt 			HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin)

typedef struct{
  uint32_t 	eppStart;

  uint8_t	PwrSetUp;
  uint8_t	TimeSetUp;

  uint32_t 	eppEnd;

}Epprom_str;

typedef enum{
 _RLHEAT,
 _MAX_OUTPUT
}CtrlName_t;

typedef enum{
 _adcVaristor,
 //_adcPtcTempWater,
 //_adcHeatSink,
 //...
 _adcTotal
}AdcManagerId_t;

void HW_RLSOL_BaseCtrl(uint8_t ON_OFF);

void heatCtrlInit();
void heatCtrlLoop();
void heatCtrl_1msIrqHandle();

extern OUTPUT_t _ctrlOutput[_MAX_OUTPUT];
extern button_t HW_Button;
extern uint16_t hw_AdcArr[_adcTotal];
extern Epprom_str _eppConfig;
//Epprom64_u flashDataInfor[_EPPR_MAX];
