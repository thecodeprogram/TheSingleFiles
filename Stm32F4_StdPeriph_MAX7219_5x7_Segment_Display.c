/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 31.10.2020
*/


#include "stm32f4xx.h"         

//PB6 CLOCK	
//PB7 CHIP SELECT
//PB5 MOSI (MASTER OUT SLAVE IN)

#define DECODE_REGISTER        0x09     
#define INTENSITY_REGISTER     0x0A   
#define SCAN_LIMIT_REGISTER    0x0B  
#define SHUTDOWN_REGISTER      0x0C
#define DISPLAY_TEST_REGISTER  0x0F 

#define DIGIT_1_REGISTER       0X01
#define DIGIT_2_REGISTER       0X02
#define DIGIT_3_REGISTER       0X03
#define DIGIT_4_REGISTER       0X05
#define DIGIT_5_REGISTER       0X04

#define DELAY_TIME 1

void the_delay(int i)
{
	while(i) i--;
}

void MAX7219_PutByte(uint8_t data)
{
  uint8_t i = 8;
  uint8_t mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
    if (data & mask){ 
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
    }else{
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
    }
		GPIO_SetBits(GPIOB, GPIO_Pin_6);
    --i; 
  } 
}

void MAX7219_SendData(char reg, char data)
{
  GPIO_ResetBits(GPIOB, GPIO_Pin_7); 
  MAX7219_PutByte(reg);  
  MAX7219_PutByte(data);  
  GPIO_SetBits(GPIOB, GPIO_Pin_7); 
  GPIO_SetBits(GPIOB, GPIO_Pin_7); 
	
	the_delay(DELAY_TIME);
}

int main()
{
	//Firstly activate the periph bus
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	//and activate the required pins
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;  
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7; 
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
	//then we are going to prepare the MAX7219 chip
	MAX7219_SendData(SHUTDOWN_REGISTER, 1);  
	MAX7219_SendData(SCAN_LIMIT_REGISTER, 0x04); 
  MAX7219_SendData(DECODE_REGISTER, 0xff); 
  MAX7219_SendData(INTENSITY_REGISTER, 0xff);  
	
	//and write the characters on display.
	MAX7219_SendData(DIGIT_1_REGISTER, 1); 
	MAX7219_SendData(DIGIT_2_REGISTER, 2); 
	MAX7219_SendData(DIGIT_3_REGISTER, 3); 
	MAX7219_SendData(DIGIT_4_REGISTER, 4); 
	MAX7219_SendData(DIGIT_5_REGISTER, 5); 
	
	while(1)
	{

	}
}
	
