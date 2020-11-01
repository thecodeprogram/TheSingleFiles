#include "stm32f4xx.h"                  // Device header


/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 01.11.2020
*/


/*
B15 DIN
B13 CLOCK
E7  CS
*/


uint32_t delay_counter;
unsigned char digits[5];

void write_MC14489( uint8_t digitData) {

  int i=0;
  int pinState;

	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);

  for (i=7; i>=0; i--)  {
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
    if ( digitData & (1<<i) ) {
			GPIO_SetBits(GPIOB, GPIO_Pin_15);
    }
    else {  
      GPIO_ResetBits(GPIOB, GPIO_Pin_15);
    }

    GPIO_SetBits(GPIOB, GPIO_Pin_13);
    GPIO_ResetBits(GPIOB, GPIO_Pin_15);
  }

  GPIO_ResetBits(GPIOB, GPIO_Pin_13);
}


void writeDigits(unsigned char digits[5])
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_7);
	
	write_MC14489(  (0xff << 4) | digits[3]  ); // D23~D16
   	write_MC14489(  (digits[4] << 4) | digits[2]); // D15~D8
   	write_MC14489(  (digits[1] << 4) | digits[0] ); // D7~D0
   
   	GPIO_SetBits(GPIOE, GPIO_Pin_7);
}

void startDisplay()
{
   GPIO_ResetBits(GPIOE, GPIO_Pin_7);
	
   write_MC14489( 0x01);
   
   GPIO_SetBits(GPIOE, GPIO_Pin_7);
}

void startCounter(){
	
	for(int i=0; i<100000; i++){
		digits[0] = i % 100000 /10000;
      	digits[1] = i % 10000  /1000;
      	digits[2] = i % 1000   /100;
      	digits[3] = i % 100   / 10 ;
      	digits[4] = i % 10     ;
      
      	writeDigits(digits);
		
		delay_counter = 8000000;
		while(delay_counter--);
	}
}



int main()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_Structure;
	
	GPIO_Structure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_Structure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15; 
	GPIO_Structure.GPIO_OType = GPIO_OType_PP; 
	GPIO_Structure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_Init(GPIOB, &GPIO_Structure); 
	
	GPIO_Structure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Structure.GPIO_Pin =  GPIO_Pin_7 | GPIO_Pin_8; 
	GPIO_Structure.GPIO_OType = GPIO_OType_PP; 
	GPIO_Structure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_Init(GPIOE, &GPIO_Structure); 
	
	startDisplay();
	
	while(1)
	{	
		startCounter();

		delay_counter = 65000;
     	while(delay_counter--);
	}

}


