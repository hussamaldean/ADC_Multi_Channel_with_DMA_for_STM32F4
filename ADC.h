#ifndef __adc__h
#define __adc__h
#include "stdint.h"
#include "stm32f4xx.h"                  // Device header
void start_adc(void);
uint16_t get_adc(int i);



#endif