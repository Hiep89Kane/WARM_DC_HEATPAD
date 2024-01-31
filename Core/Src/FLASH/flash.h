#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "myHeader.h"

//#define GetPage(Addr) ((Addr - FLASH_BASE) / FLASH_PAGE_SIZE)//trả về vị trí Page của 1 địa chỉ bất kỳ
// luu y : stm32f030 : co 64 pages , moi page 1k byte ,FLASH_PAGE_SIZE :  0x400U = 1024 bytes ~ 1kb
#define ADDR_FLASH_PAGE_63 0x0800FC00 /* Start @ of user Flash area =>  last byte of page 63 is 0x0801 FC00 */
#define	FLASH_ADDRESS_START ADDR_FLASH_PAGE_63

///@chu y: sau bien ket thuc can luu vao flash phai trong 4byte
void flash_init_address(uint32_t *address_start, uint32_t *address_end);
void flash_update(void);
void flash_read(void);
uint8_t flash_erase(uint32_t ADR_StartPage, uint32_t numPages);


uint8_t Flash_ReadByte(uint32_t ADR);
uint32_t Flash_ReadWord(uint32_t ADR);
uint64_t Flash_ReadDWord(uint32_t ADR);

#endif /* INC_FLASH_H_ */
