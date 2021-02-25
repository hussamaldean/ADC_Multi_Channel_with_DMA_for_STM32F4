#include "GLCD_ST7735.h"
#include "stdio.h"
#include "adc.h"
#define YMAX 5000
#define YMIN 0
uint16_t temp[3];
char print[20];

void drawaxes(void){
ST7735_Drawaxes(AXISCOLOR, BGCOLOR, "Time", "ADC", LIGHTCOLOR, "", 0, YMAX, YMIN);
}


void drawInfoBar(void)
{
//sprintf(print,"%u",temp);
ST7735_DrawString(1, 0, "CPU =", GREEN);
ST7735_DrawString(7, 0, "75%", BLUE );
ST7735_DrawString(11, 0, "ADC=", GREEN);
ST7735_DrawString(18, 0, print, BLUE );

}



void plot(void)
{

//ST7735_PlotPoint(temp,GREEN);
ST7735_PlotIncrement();
}

int main(void)
{

start_adc();
LCD_CS0;
ST7735_Init();
ST7735_FillScreen(BLACK);
//drawaxes();
//drawInfoBar();
//LCD_CS1;
	
while(1)
{
LCD_CS0;
temp[0]=get_adc(0);
temp[1]=get_adc(1);
temp[2]=get_adc(2);
sprintf(print,"ADC1_CH0=%u",temp[0]);
ST7735_DrawString(0, 0,print, GREEN);	

sprintf(print,"ADC1_CH1=%u",temp[1]);
ST7735_DrawString(0, 5,print, GREEN);


sprintf(print,"ADC1_CH2=%u",temp[2]);
ST7735_DrawString(0, 10,print, GREEN);
//
//drawInfoBar();	
//plot();
LCD_CS1;

}

}