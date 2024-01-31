#if !defined (COMMON__H)
    #define COMMON__H 

#include "stdint.h"
/* Comment the below line to disable REM232 debug */
//Phai co dau () cho ca Macro de khong nham thuat toan
/*Clear bit*/
#ifndef cbi 
    #define cbi(port, bit)       ((port) &= ~(1 << (bit)))
#endif

/*Set bit*/
#ifndef sbi 
    #define sbi(port, bit)       ((port) |=  (1 << (bit)))
#endif

/*Read bit*/
#ifndef rbi 
    #define rbi(pin, bit)        (((pin) >> (bit))&0x01)      
#endif

/*Write bit*/
#ifndef wbi
    #define wbi(port, bit, val)  ((val)? (sbi(port, bit)) : (cbi(port, bit)))
#endif

/*toggle bit*/
#ifndef tbi
	#define tbi(port, bit) 	   			((port) ^=  (1 << (bit)))
#endif

#define _TOGGLE_BYTE(BYTE)      ((BYTE) =(~BYTE) & 0x01)
#define _LIMIT(X,min,max)	((X>=min) && (X<=max))

typedef enum{
	_FALSE,
	_TRUE = !_FALSE
}ResultStatus;

typedef enum{
	_FAIL,
	_PASS = !_FAIL
}CheckStatus;

typedef enum{
	_ERROR,
	_SUCCESS = !_ERROR
}ProcessStatus;

typedef enum{
	_CLEAR,
	_SET = !_CLEAR
}Flag_Status;
    
typedef enum{
	_LOW,
	_HIGH = !_LOW
}LogicStatus;

typedef enum{
	_DISABLE,
	_ENABLE = !_DISABLE
}FuncStatus;

typedef enum{
	_DEACTIVE,
	_ACTIVE = !_DEACTIVE
}ActiveStatus;

typedef enum{
	_NOT_BUSY,
	_BUSY = !_NOT_BUSY
}OperateStatus;

/*check if char is number macro*/
#define isnumber(num) ((num >= 48) && (num < 58))
/*check if char is hexa number macro*/
#define ishexnumber(num) (((num >= 48) && (num < 58)) || ((num >= 65) && (num < 71)) || ((num >= 97) && (num < 103)))
/*check if char is uncased char macro*/
#define isUNCASEDchar(num) ((num >= 'a') && (num <= 'z'))
/*check if char is cased char macro*/
#define isCASEDchar(num) ((num >= 'A') && (num <= 'Z'))
/*check if char is readable char macro*/
#define isreadable(num) ((num >= ' ') && (num <= '~'))
    
/*Define Reset Const*/ 
#define		_MCU_WDT_Init()			HAL_IWDG_Init(&hiwdg)
#define		_MCU_WDT_Refresh()		HAL_IWDG_Refresh(&hiwdg)

void 		delay_ms(uint32_t ms);

void    	uncase_to_case(char *str);
char    	strchecksum(char *str);

uint8_t   	Str2HexChar(char *str, uint8_t *HexChar);
void    	HexChar2Str(char *str, uint8_t HexChar);
uint32_t  	Str2Num(char *str);
void    	Num2Str(char *str, uint32_t number);

#endif

/* [] END OF FILE */
