#include "ADC.h"
uint32_t tempo; 
uint32_t ADC1_Value;

void ADC_Init(void){
	
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN; 
	
RCC->APB2ENR|=RCC_APB2ENR_ADC1EN; 

RCC->AHB1ENR|=(1<<21)|(1<<22);	
	
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	
RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;
	
GPIOA->MODER|=0b00001111; 
	
ADC1->CR2=0; 
	
ADC1->SMPR2|=0b00111111;
	
ADC1->SQR3=0;
	
ADC1->CR2|=ADC_CR2_CONT;
	
ADC1->CR2|=1; 

ADC1->CR2|=ADC_CR2_SWSTART;	



DMA2_Stream0->PAR		=(uint32_t)(0x4001204C);

DMA2_Stream0->M0AR 	=(uint32_t)(&(ADC1_Value));

DMA2_Stream0->NDTR	=1;

DMA2_Stream0->CR	 |=(1<<14)|(1<<12)|(1<<10)|(1<<8)|(1<<17)|(1<<16);

DMA2_Stream0->FCR  |=(0x03);

DMA2_Stream0->CR	 |=0x0001;




}

void start_adc(void)
{

ADC_Init();

}

uint16_t get_adc(int i)
{

return ADC1_Value;
} 

