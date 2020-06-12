/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 13.06.2020
*/



#include "stm32f4xx.h"    // Device header


void delay(uint32_t sure)
{
	uint32_t counter;
	for(int i=0;i<sure;i++){
		counter++;
	}
}

int main()
{
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7; 
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_100MHz; 
	GPIO_Init(GPIOD, &GPIO_InitStructure); 
		
	
	while(1)
	{
		GPIOD->ODR = 0x01; // 0b0000 0001
	
		for(uint16_t i = 0;i < 8; i++)
		{
			GPIOD->ODR = GPIOD->ODR << 1;
			delay(1000000);
		}
		
		for(uint16_t i=8; i>0; i--)
		{
			GPIOD->ODR = GPIOD->ODR >> 1;
			delay(1000000);
		}
		
		delay(1000000);
	}
		
}
