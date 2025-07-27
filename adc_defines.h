//adc_defines.h
#include "types.h"
//cfg operating freq of ADC peripheral
#define FOSC 12000000 //Hz
#define CCLK (FOSC*5) // Hzas per startup
#define PCLK (CCLK/4) // Hz as per startup
#define ADC_CLK 3000000 //our requirement

//defines for sfr ADCR
#define CLKDIV         ((PCLK/ADC_CLK)-1)
#define PDN_BIT        21
#define ADC_START_BIT  24
#define BURST_BIT      16

//defines for sfr ADDR
#define RESULT_BITS    6
#define DONE_BIT       31
