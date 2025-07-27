//adc.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "adc_defines.h"

void Init_ADC(void)
{
  //cfg onchip ADC peripheral
  ADCR=((1<<PDN_BIT)|(CLKDIV<<8));
}

f32 Read_ADC(u32 channelNo)
{
	u32 adcVal=0;
	f32 eAR;
	
	//clear Analog Input lines selection
	ADCR&=0xFFFFFF00;
	//select analog input line & start conv
	ADCR|=((1<<ADC_START_BIT)|(1<<channelNo));
	//wait for conv time
	delay_us(3);
	
	while(((ADDR>>DONE_BIT)&1)==0);
	
	adcVal=((ADDR>>RESULT_BITS)&1023);
	
  //stop adc conv
  ADCR&=~(1<<ADC_START_BIT);
  //read equivalent analog reading 	
	eAR=((3.3/1024)*adcVal);
	return eAR;
}
