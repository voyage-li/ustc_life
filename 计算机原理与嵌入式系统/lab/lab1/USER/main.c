#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"	
#include "dip.h"



int main(void)
{ 
	
	LED_Init();		       //初始化LED端口
	delay_init(168);     //初始化延时函数
	DIP_Init();
	
	while(1)
	{
		LED0=DIP0;
		LED1=DIP1;
		LED2=DIP2;
		LED3=DIP3;
		LED4=DIP4;
		LED5=DIP5;
		LED6=DIP6;
		LED7=DIP7;
 	}
}
