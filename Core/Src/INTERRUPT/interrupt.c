#include "myHeader.h"

void (*callbackSystickHandle)(void) = &heatCtrl_1msIrqHandle;

/**
  * @brief  Conversion complete callback in non-blocking mode.
  * @param hadc ADC handle
  * @retval None
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadcX){
  //80-120us
  if (hadcX->Instance == hadc.Instance){
  }

}

/**
  * @brief  SYSTICK callback.
  * @retval None
  */
void HAL_SYSTICK_Callback(void){
  if(callbackSystickHandle)
    callbackSystickHandle();
}


