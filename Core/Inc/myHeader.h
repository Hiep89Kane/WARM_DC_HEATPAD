#ifndef INC_MYHEADER_H_
#define INC_MYHEADER_H_

#include "main.h"

#include "stdint.h"
#include "string.h"
#include "stdarg.h"

#include "common.h"
#include "timeVirtural/timer_virtural.h"
#include "button/button.h"
#include "output/output.h"
#include "kalman/kalman.h"
#include "flash.h"
#include "lcd_i2c.h"
#include "interrupt.h"
#include "heatCtrl.h"

#define _USER_DEFINE_I2C_INA219	hi2c1
#define _USER_DEFINE_I2C_LCD	hi2c1

extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;
extern IWDG_HandleTypeDef hiwdg;

#endif /* INC_MYHEADER_H_ */

