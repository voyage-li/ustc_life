#ifndef __LED_H
#define __LED_H
#include <sys.h>	 

#define LED0 PGout(11)
#define LED1 PGout(10)	 
#define LED2 PGout(9)
#define LED3 PDout(7)	 
#define LED4 PGout(3)
#define LED5 PGout(2)	 
#define LED6 PDout(13)
#define LED7 PDout(12)	 	 

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

void LED_Init(void);
	
#endif
