// lm35.c
#include "adc.h"
#include "lm35.h"
#include "types.h"

u32 Read_Temp(u8 tempType)
{
    static u32 flag;   // Static variable to initialize ADC only once
    u32 adcVal;        // Variable to store ADC result
    f32 eAR;           // Variable to store equivalent analog reading

    if (flag == 0)
    {
        Init_ADC();    // Initialize ADC once
        flag = 1;
    }

    Read_ADC(0, &adcVal, &eAR);   // Read ADC value from Channel 0
		
    return eAR * 100;             // Convert to Celsius by scaling
}

/*
u32 Read_Temp(void)
{
    static u32 flag;   // Static variable to initialize ADC only once
    u32 adcVal;        // Variable to store ADC result
    f32 eAR;           // Variable to store equivalent analog reading

    if (flag == 0)
    {
        Init_ADC();    // Initialize ADC once
        flag = 1;
    }

    Read_ADC(0, &adcVal, &eAR);   // Read ADC value from Channel 0
		
    return eAR * 100;             // Convert to Celsius by scaling
}
*/
