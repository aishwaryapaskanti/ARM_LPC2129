
# ARM7_LPC2129

![Blue and White Modern Professional General Linkedin Banner (1)](https://github.com/user-attachments/assets/3a137d8d-efa7-4aaa-9e22-46d5cb8423bb)


__INDEX__

01. Title: Led Light blinking System Using LPC2129
02. Title: Traffic Light System Using LPC2129
03. Title: LED Binary Counter (1 to 255) Using LPC2129
04. Title: Electronic Dice Using LPC2129
05. Title: Switch-Controlled LED Using LPC2129
06. Title: Dual Switch-Controlled LED Using LPC2129
07. Title: 4 Switches Controlling 4 LEDs Using LPC2129
08. Title: 7-Segment Display Digit Test Using LPC2129
09. Title: Dual-Digit 7-Segment Multiplexed Display Test Using LPC2129
10. Title: Electronic Dice Simulation on 7-Segment Display Using LPC2129
11. Title: 60-Second Stopwatch Using LPC2129 and 7-Segment Display
12. Title: 60-Second Timer with Increment, Decrement, and Reset Using LPC2129
13. Title: LCD Functionality Test Using LPC2129
14. Title: Displaying Capital Alphabets with ASCII Values on 16x2 LCD
15. Title: Electronic Dice Simulation Using LCD Display
16. Title: Scrolling and Oscillating Message Display on LCD Using LPC2129
17. Title: Fastest Finger First Timer using LCD and LPC2129 Microcontroller
18. Title: Fastest Finger First System Using LPC2129 with 7-Segment Display
19. Title: 4x4 Matrix Keypad Interface and Display Test Using LPC2129 and LCD
20. Title: SMS-Style Text Entry Using 4x4 Keypad and LCD with LPC2129
21. Title: ADC Value Display on LCD using LPC2129
22. Title: Temperature Monitoring using LM35 Sensor and LPC2129 with LCD Display
23. Title: Distance Measurement using GP2D12 Sensor with LPC2129 and LCD Display
24. Title: DHT11 Interfacing with LPC2129 for Temperature and Humidity Monitoring
25. Title: 20x4 LCD Interface with LPC2129 for Multi-Format Data Display

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

__1. Title: Led Light blinking System Using LPC2129__

*Objective:* To understand and implement LED control using a microcontroller by turning it on and off at a fixed interval.

__Hardware Connection:__
 - LPC2129 P0.7 --> LED
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/f485e25e-c045-4cff-baaf-f41cabf6eb34)


__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 44 17_8f3f53d1](https://github.com/user-attachments/assets/e60e9c8c-3bac-49ab-8017-da5320f3e445)


__Code:__
```
#include <lpc21xx.h>
void delay_s(unsigned int dly)
{
	dly=dly*12000000;
	while(dly--);
}
#define LED 7
int main()
{
	IODIR0 |=1<<LED;
	while(1)
	{
		IOSET0=1<<LED;
		delay_s(1);
		IOCLR0=1<<LED;
		delay_s(1);
	}
}
```

_________________________________________________________________________________________________________________________________________________________________________

__2. Title: Traffic Light System Using LPC2129__

*Objective:* Design a traffic light system using Red, Yellow, and Green LEDs that mimic real-world traffic signals. 

__Hardware Connection:__
 - LPC2129 P0.10 --> LED red
 - LPC2129 P0.11 --> LED yellow
 - LPC2129 P0.12 --> LED green
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/acad53e2-bd15-44ed-8595-1399c0006f53)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 46 45_7f1b8858](https://github.com/user-attachments/assets/11e948b9-e458-441e-911c-aae650d14624)

![WhatsApp Image 2025-06-03 at 13 46 46_e4747bb2](https://github.com/user-attachments/assets/cbc25d67-509a-4281-93de-0f917cbf7d22)


__Code:__
```
#include <lpc21xx.h>
#define RED_LED    (1 << 10)  // P0.10
#define YELLOW_LED (1 << 11)  // P0.11
#define GREEN_LED  (1 << 12)  // P0.12
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 1000; j++); // Rough delay loop
    }
}
int main(void)
{
    // Configure P0.10, P0.11, P0.12 as output
    IO0DIR |= (RED_LED | YELLOW_LED | GREEN_LED);
    while (1)
    {
        // Red LED ON (Stop Signal)
        IO0SET = RED_LED;
        IO0CLR = YELLOW_LED | GREEN_LED;
        delay_ms(5000);
        // Yellow LED ON (Get Ready Signal)
        IO0SET = YELLOW_LED;
        IO0CLR = RED_LED | GREEN_LED;
        delay_ms(2000);
        // Green LED ON (Go Signal)
        IO0SET = GREEN_LED;
        IO0CLR = RED_LED | YELLOW_LED;
        delay_ms(5000);
    }
}
```
___________________________________________________________________________________________________________________________________________________________

__3. Title: LED Binary Counter (1 to 255) Using LPC2129__

*Objective:*\
To interface 8 LEDs with the LPC21xx microcontroller and display binary counting from 1 to 255 by toggling the LEDs accordingly. The program configures Port 0 (pins P0.4 to P0.11) as output and sequentially updates the LED states in a loop with a delay of 100ms between each count.

__Hardware Connection:__
 - LPC2129 P0.4 --> LED
 - LPC2129 P0.5 --> LED 
 - LPC2129 P0.6 --> LED
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/af9019a4-3a5e-44ec-bc29-3fb3053d4a9d)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 48 30_ee8612a9](https://github.com/user-attachments/assets/d412ae78-947d-4b05-8690-a3152e65e44c)

![WhatsApp Image 2025-06-03 at 13 48 31_8aed1a3b](https://github.com/user-attachments/assets/095caa29-4cab-4826-847c-0e5aae2d2593)

![WhatsApp Image 2025-06-03 at 13 48 31_b0827ac1](https://github.com/user-attachments/assets/9507d1a6-c906-4288-ba2e-0f0346f251ba)

![WhatsApp Image 2025-06-03 at 13 48 31_100375dd](https://github.com/user-attachments/assets/e2f6930d-7ad4-4f0f-b09a-8b2092a636c8)


__Project Code:__
```
//led_8_al_binary_1_to_255.c
#include <lpc21xx.h>
#include "delay.h"
#include "types.h"
#define LED_8_AL 4 //port0.4 to 0.11
main()
{	u32 i;
	//cfg p0.4 to p0.11 pin as output
	IODIR0|=0xFF<<LED_8_AL;
	
	for(i=0; i<=255; i++)
	{
		IOPIN0=((IOPIN0&~(0xFF<<LED_8_AL))|(~i<<LED_8_AL));
		delay_ms(100);
	}
	while(1);
}
```

__________________________________________________________________________________________________________________________________________________________________________________
__4. Title: Electronic Dice Using LPC2129__

*Objective:*\
To simulate the rolling of a 3-bit electronic dice using an LPC21xx microcontroller. The program configures three LED pins (P0.4 to P0.6) as outputs to represent dice face values (1 to 6). A random number is generated using rand(), displayed on the LEDs in binary form, and updated every second. The srand() function is used to change the seed value for randomness in successive rolls.

__Hardware Connection:__
 - LPC2129 P0.4 --> LED
 - LPC2129 P0.5 --> LED 
 - LPC2129 P0.6 --> LED
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/bc866bf0-84d7-478a-bea6-1d4a2a4afb94)

__Hardware simulation:__

![WhatsApp Image 2025-06-03 at 13 49 35_08b6ece4](https://github.com/user-attachments/assets/61dbcb44-4ae6-4e34-b5d6-ae060a719e8d)

![WhatsApp Image 2025-06-03 at 13 49 35_c65d90e1](https://github.com/user-attachments/assets/43fba1d4-2a2d-402f-a3ce-b1e5ec7d2b6a)


__Project Code:__
```
//electronics_dice_01.c
#include <lpc21xx.h>
#include <stdlib.h>
#include "types.h"
#include "delay.h"
#define LED_3_AL 4 //P0.4 to p0.6
u32 faceVal;
main()
{
	u32 seed=0;
		//cfg p0.4 to p0.6 as output pin 
		IODIR0|=(7<<LED_3_AL);
		
		while(1)
		{
			faceVal=(rand()%6)+1;
			IOPIN0=((IOPIN0&~(7<<LED_3_AL))|(~faceVal<<LED_3_AL));
			delay_ms(1000);
			srand(seed++);
		}
}
```

_____________________________________________________________________________________________________________________________________________________________________________________

__5. Title: Switch-Controlled LED Using LPC2129__

*Objective:*\
To interface a switch and an LED with the LPC21xx microcontroller, where the LED toggles based on the switch's state. The program configures P0.0 as an input (switch) and P0.4 as an output (LED). If the switch is pressed (logic LOW), the LED turns OFF; otherwise, it remains ON.

__Hardware Connection:__
 - LPC2129 P0.0 --> active low switch
 - LPC2129 P0.4 --> active low led
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/eea58c26-a4c5-4f3a-a0aa-0e41abdfde90)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 50 56_ecacd064](https://github.com/user-attachments/assets/804cf757-dddf-4ec3-b698-d815b851a1c1)

![WhatsApp Image 2025-06-03 at 13 50 56_7722dfde](https://github.com/user-attachments/assets/0c73d194-a826-4494-a45a-5282af4ffbe4)


__Project code:__
```
//SW_AL_LED_01.c
#include <lpc21xx.h>
#include "delay.h"
#define SW_AL 0
#define LED_AL 4
main()
{
	//cfg p0.0 as input pin 
	IODIR0&=~(1<<SW_AL);
	
	//cfg p0.4 as output pin 
	IODIR0|=(1<<LED_AL);
	
	while(1)
	{
			if(((IOPIN0>>SW_AL)&1)==0)
				IOCLR0=1<<LED_AL;
			else
				IOSET0=1<<LED_AL;
	}
}
```

____________________________________________________________________________________________________________________________________________________________________________________
__6. Title: Dual Switch-Controlled LED Using LPC2129__

*Objective:*\
To interface two switches and one LED with the LPC21xx microcontroller, where the LED responds based on the state of both switches. The program configures P0.0 and P0.1 as input pins (switches) and P0.4 as an output pin (LED). The LED turns OFF if either switch is pressed (logic LOW) and remains ON when both switches are released (logic HIGH). 

__Hardware Connection:__
 - LPC2129 P0.0 --> active low switch
 - LPC2129 P0.1 --> active low switch
 - LPC2129 P0.4 --> active low led
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/e7f2882b-73fa-4a2a-b74f-5e071916387c)

__Hawdware Simulation:__

![WhatsApp Image 2025-06-03 at 13 52 03_49a8e387](https://github.com/user-attachments/assets/29436c9a-a8d2-423d-9e90-ab2fa3bd9442)

![WhatsApp Image 2025-06-03 at 13 52 02_a7521c3b](https://github.com/user-attachments/assets/1a8628bf-84c1-448a-96ad-045901300d7d)

![WhatsApp Image 2025-06-03 at 13 52 03_cd06df9a](https://github.com/user-attachments/assets/89c0fca7-c4e3-4de2-9e77-067fd2449da6)


__Project code:__
```
//AL_2_SW_AL_1_LED.c

#include <lpc21xx.h>
#include "delay.h"
#define SW_AL_1 0
#define SW_AL_2 1
#define LED_AL 4
main()
{
	//cfg pin p0.0 and p0.1 as input 
	IODIR0&=~(3<<SW_AL_1);
	
	//cfg pin p0.4 as output 
	IODIR0|=(1<<LED_AL);
	while(1)
	{
		if((((IOPIN0>>SW_AL_1)&1)==0)||(((IOPIN0>>SW_AL_2)&1)==0))
		{
			IOCLR0=1<<LED_AL;
		}
		else
		{
			IOSET0=1<<LED_AL;
		}
	}
}
```

_______________________________________________________________________________________________________________________________________________________________________________________________
__7. Title: 4 Switches Controlling 4 LEDs Using LPC2129__

*Objective:*\
To interface four switches and four LEDs with the LPC21xx microcontroller, where each switch controls a corresponding LED. The program configures P0.0 to P0.3 as input pins (switches) and P0.4 to P0.7 as output pins (LEDs). The LED states directly reflect the switch states, meaning each LED turns ON or OFF based on its respective switch input.

__Hardware Connection:__
 - LPC2129 P0.0 --> active low switch
 - LPC2129 P0.1 --> active low switch
 - LPC2129 P0.2 --> active low switch
 - LPC2129 P0.3 --> active low switch
 - LPC2129 P0.4 --> active low led
 - LPC2129 P0.5 --> active low led
 - LPC2129 P0.6 --> active low led
 - LPC2129 P0.7 --> active low led
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/c29b9b4e-5ea7-4750-b3be-52d92819abcb)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 53 19_af2287e8](https://github.com/user-attachments/assets/543a53d9-e511-498a-952f-e22041512191)

![WhatsApp Image 2025-06-03 at 13 53 19_cfe0169b](https://github.com/user-attachments/assets/8b171eb5-7989-4aad-8acd-356c288a7f74)

![WhatsApp Image 2025-06-03 at 13 53 20_7b73a70f](https://github.com/user-attachments/assets/15b7dd9b-edb9-4563-a98a-b622e7132e8d)

![WhatsApp Image 2025-06-03 at 13 53 20_11f01163](https://github.com/user-attachments/assets/5a645782-8b11-406d-8423-dc863a6393a0)

![WhatsApp Image 2025-06-03 at 13 53 20_18d97c98](https://github.com/user-attachments/assets/8f925944-78a5-4b72-92d2-50ae22731fef)


__Project Code:__
```
//AL_4_SW_AL_4_LED.c

#include <lpc21xx.h>
#include "delay.h"
#define SW_AL_1 0
#define SW_AL_2 1
#define SW_AL_3 2
#define SW_AL_4 3
#define LED_AL_1 4
#define LED_AL_2 5
#define LED_AL_3 6
#define LED_AL_4 7
main()
{
	//cfg pin p0.0 and p0.1 as input 
	IODIR0&=~(0x0F<<SW_AL_1);
	
	//cfg pin p0.4 as output 
	IODIR0|=(0X0F<<LED_AL_1);
	while(1)
	{
			IOPIN0=((IOPIN0&0x0F)<<LED_AL_1);
	}
}
```
___________________________________________________________________________________________________________________________________________________

__8. Title: 7-Segment Display Digit Test Using LPC2129__

*Objective:*\
To interface a common anode 7-segment display with the LPC21xx microcontroller and sequentially display digits from 0 to 9. The program configures P0.8 to P0.15 as output pins for segment control. A lookup table (LUT) stores the segment patterns for digits 0-9, which are displayed sequentially with a 1-second delay between each update.

__Harware Connection:__
 - LPC2129 P0.8 --> a
 - LPC2129 P0.9 --> b
 - LPC2129 P0.10 --> c
 - LPC2129 P0.11 --> d
 - LPC2129 P0.12 --> e
 - LPC2129 P0.13 --> f
 - LPC2129 P0.14 --> g
 - LPC2129 P0.15 --> dp
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/ebd898a9-fe17-4e48-8fa9-d5a979c399ba)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 55 00_b0a6e6a5](https://github.com/user-attachments/assets/d8a71929-60b9-4219-85ac-87ecdcb5207a)

![WhatsApp Image 2025-06-03 at 13 55 00_e1fe6ffb](https://github.com/user-attachments/assets/ddc4a091-5909-45da-b89d-4fdb3d8707f2)

![WhatsApp Image 2025-06-03 at 13 55 00_8800a840](https://github.com/user-attachments/assets/1792cf65-b006-41f5-b368-ebe71fee1f11)


__Project Code:__
```
//ca7segement_test.c
// 7-Segment Display

#include <lpc21xx.h>      // Correct header for LPC2129
#include "types.h"
#include "delay.h"        // Delay function header

// Common Anode Segment Lookup Table (LUT) for digits 0-9
u8 ca_segLUT[10] = {
    0xC0,  // 0
    0xF9,  // 1
    0xA4,  // 2
    0xB0,  // 3
    0x99,  // 4
    0x92,  // 5
    0x82,  // 6
    0xF8,  // 7
    0x80,  // 8
    0x90   // 9
};

#define CA_SEG 8   // Starting pin position for segments (P0.8 to P0.15)

main()
{
    u32 i;  // Variable for loop iteration

    // Configure pins P0.8 to P0.15 as output for 7-segment display
    IODIR0 |= (0xFF << CA_SEG);  

    while(1)
    {
        for (i = 0; i < 10; i++)
        {
					IOPIN0=(IOPIN0&~(0XFF<<CA_SEG)|(ca_segLUT[i]<<CA_SEG));
					delay_ms(1000);
					
					/*
            // Clear the previous digit
            IOCLR0 = (0xFF << CA_SEG);

            // Display the current digit
            IOSET0 = ((ca_segLUT[i]) << CA_SEG);

            // Delay for 1 second (1000ms)
            delay_ms(1000);  
*/        }
    }
}
```

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________

__9. Title: Dual-Digit 7-Segment Multiplexed Display Test Using LPC2129__

*Objective:*\
To interface a dual-digit 7-segment display with the LPC21xx microcontroller using multiplexing. The program initializes the 7-segment display, then sequentially displays numbers from 00 to 99. Multiplexing is implemented by refreshing the display multiple times (using a loop) to ensure both digits remain visible to the human eye.

__Hardware Simulation:__
 - LPC2129 P0.8 --> a1, a2
 - LPC2129 P0.9 --> b1, b2
 - LPC2129 P0.10 --> c1, c2
 - LPC2129 P0.11 --> d1, d2
 - LPC2129 P0.12 --> e1, e2
 - LPC2129 P0.13 --> f1, f2
 - LPC2129 P0.14 --> g1, g2
 - LPC2129 P0.15 --> dp1, dp2
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/7393be86-7a30-426d-95ad-240a0d83fd4a)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 56 04_1e04c062](https://github.com/user-attachments/assets/db34b83e-5211-4fc4-8d08-d45f00c08671)

![WhatsApp Image 2025-06-03 at 13 56 05_9f3299e3](https://github.com/user-attachments/assets/03d78143-1331-454b-989a-6718e12de8d8)


__Project Code:__
```
//ca7seg_2_mux_test_2.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
main()
{
	u32 i,j;
	Init7Segs();
	while(1)
	{
		for(i=0;i<=99;i++)
		{
			for(j=50;j>0;j--)
			{
				disp_2_mux_segs(i);
			}	
		}
	}
}
```
___________________________________________________________________________________________________________________________________________________
__10. Title: Electronic Dice Simulation on 7-Segment Display Using LPC2129__

*Objective:*\
To simulate the rolling of a dice using an LPC21xx microcontroller and display the result on a 7-segment display. The program initializes the 7-segment display and continuously shows the last rolled dice value. When a button (connected to P1.16) is pressed, a new random dice face value (1 to 6) is generated using rand(), and the display is updated accordingly using multiplexing.

__Hardware Connection:__
 - LPC2129 P0.8 --> a
 - LPC2129 P0.9 --> b
 - LPC2129 P0.10 --> c
 - LPC2129 P0.11 --> d
 - LPC2129 P0.12 --> e
 - LPC2129 P0.13 --> f
 - LPC2129 P0.14 --> g
 - LPC2129 P0.15 --> dp
 - LPC2129 P1.16 --> active switch
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/e3b8e8b9-1ef1-45a6-b404-93be6895769c)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 13 57 05_5033a124](https://github.com/user-attachments/assets/6ed0c7b8-3327-4307-a18f-88be4cf5f1e0)

![WhatsApp Image 2025-06-03 at 13 57 05_4707ee8b](https://github.com/user-attachments/assets/17cc82d8-0b5c-410c-97f1-b4461ae210e7)


__Project Code:__
```
//electronic_dice_7_segment.c

#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
#include <stdlib.h>
#define ROLL_SW_AL 16//@p1.16
main()
{
	u32 faceVal=0,seed=0,dly;
	Init7Segs();
	while(1)
	{
		disp_2_mux_segs(faceVal);
		
		if(((IOPIN1>>ROLL_SW_AL)&1)==0)
		{
			faceVal=(rand()%6)+1;
			srand(seed++);
			for(dly=25;dly>0;dly--)
			{
				disp_2_mux_segs(faceVal);
			}	
		}	
		
	}
}
```

____________________________________________________________________________________________________________________________________________________
__11. Title: 60-Second Stopwatch Using LPC2129 and 7-Segment Display__

*Objective:*\
To implement a stopwatch using an LPC21xx microcontroller and a 7-segment display, capable of counting up to 60 seconds. A trigger switch (connected to P1.16) is used to start, stop, and reset the stopwatch. The display continuously updates the time, and pressing the switch controls the stopwatch operation:

First Press: Starts the stopwatch.\
Second Press: Pauses the stopwatch.\
Third Press: Resets the time to zero.

__Hardware Connection:__
 - LPC2129 P0.8 --> a
 - LPC2129 P0.9 --> b
 - LPC2129 P0.10 --> c
 - LPC2129 P0.11 --> d
 - LPC2129 P0.12 --> e
 - LPC2129 P0.13 --> f
 - LPC2129 P0.14 --> g
 - LPC2129 P0.15 --> dp
 - LPC2129 P1.16 --> active switch
 - LED --> GND


__Software Simulation:__

![image](https://github.com/user-attachments/assets/241dbe90-b5b7-41e7-af22-7e93587a4108)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 18 54_2eaaae6d](https://github.com/user-attachments/assets/86115884-ec7f-458e-9e8d-6f868f2713ee)

![WhatsApp Image 2025-06-03 at 15 18 55_e55da063](https://github.com/user-attachments/assets/30ad5236-5af4-49a1-83c9-305277519520)


__Project Code:__
```
//stopwatch_60sec.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
#define TRIG_SW_AL 16//@p1.16
main()
{
	u32 time=0,flag=0,dly; 
	Init7Segs();
	while(1)
	{	
	 while(flag==0)
	 {
		disp_2_mux_segs(time);
		
		if(((IOPIN1>>TRIG_SW_AL)&1)==0)
		{
			flag=1;
			while(((IOPIN1>>TRIG_SW_AL)&1)==0)
			{
				disp_2_mux_segs(time);
			}
		}
	 }
	 
   while(flag==1)
	 {	 
		for(dly=500;dly>0;dly--)
		{
			disp_2_mux_segs(time);
			if(((IOPIN1>>TRIG_SW_AL)&1)==0)
			{
				flag=0;
				while(((IOPIN1>>TRIG_SW_AL)&1)==0)
				{
				  disp_2_mux_segs(time);
			  }	
				break;
      }	
		}
		if(flag==1)
		time++;	
		
	 }
        
	 while((flag==0)&&(time!=0))
	 {
		 disp_2_mux_segs(time);
		 if(((IOPIN1>>TRIG_SW_AL)&1)==0)
		 {
			 time=0;
			 while(((IOPIN1>>TRIG_SW_AL)&1)==0)
			 {
				disp_2_mux_segs(time);
			 }	
		 }
	 }
  }
}
```

_________________________________________________________________________________________________________________________________________

__12. Title: 60-Second Timer with Increment, Decrement, and Reset Using LPC2129__

*Objective:*\
To implement a user-controlled timer using an LPC21xx microcontroller and a 7-segment display, allowing the user to set a time value (0 to 60 seconds) using three push buttons:

Reset Button (P1.16): Resets the timer to 0.\
Increment Button (P1.17): Increases the timer count.\
Decrement Button (P1.18): Decreases the timer count.

The display continuously updates the current timer value, and button presses modify the count accordingly. The program ensures button debounce handling by waiting until the button is released before updating the count.

__Hardware Connection:__
 - LPC2129 P0.8 --> a
 - LPC2129 P0.9 --> b
 - LPC2129 P0.10 --> c
 - LPC2129 P0.11 --> d
 - LPC2129 P0.12 --> e
 - LPC2129 P0.13 --> f
 - LPC2129 P0.14 --> g
 - LPC2129 P0.15 --> dp
 - LPC2129 P1.16 --> active switch 1
 - LPC2129 P1.17 --> active switch 2
 - LPC2129 P1.18 --> active switch 3
 - LED --> GND

__Software Connection:__

![image](https://github.com/user-attachments/assets/1f7db595-4b85-40b8-8c5e-2f5cd013673f)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 19 41_9d3153f7](https://github.com/user-attachments/assets/b10a79e8-c861-43fa-a964-283537fe2ace)

![WhatsApp Image 2025-06-03 at 15 19 42_04da8c79](https://github.com/user-attachments/assets/105e51e7-0ca9-4ef8-bd72-d5af2967a26e)


__Project Code:__
```
//timer_set_60sec.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
#define RST_SW_AL 16//@p1.16
#define INC_SW_AL 17//@p1.17
#define DEC_SW_AL 18//@p1.18
main()
{
	u32 count=0;
	Init7Segs();
	while(1)
	{	
	  disp_2_mux_segs(count);
		if(((IOPIN1>>RST_SW_AL)&1)==0)
		{
			count=0;
			while(((IOPIN1>>RST_SW_AL)&1)==0)
			{
				disp_2_mux_segs(0);
			}
		}	 
	
	  if(((IOPIN1>>INC_SW_AL)&1)==0)
	  {
			count++;
			while(((IOPIN1>>INC_SW_AL)&1)==0)
			{
				disp_2_mux_segs(count);
			}
	  }
	 
	 
	  if(((IOPIN1>>DEC_SW_AL)&1)==0)
	  {
			count--;
			while(((IOPIN1>>DEC_SW_AL)&1)==0)
			{
				disp_2_mux_segs(count);
			}
	 }
	 
  }
}
```

___________________________________________________________________________________________________________________________________________________

__13. Title: LCD Functionality Test Using LPC2129__

*Objective:*\
To interface an LCD with the LPC21xx microcontroller and test various display functionalities, including character, string, integer, floating-point, hexadecimal, octal, and binary number representations. The program initializes the LCD, loads a custom character into CGRAM, and sequentially displays different types of data on the LCD to verify its proper operation.

__Hardware Connection:__
 - LPC2129 P0.8 --> d0
 - LPC2129 P0.9 --> d1
 - LPC2129 P0.10 --> d2
 - LPC2129 P0.11 --> d3
 - LPC2129 P0.12 --> d4
 - LPC2129 P0.13 --> d5
 - LPC2129 P0.14 --> d6
 - LPC2129 P0.15 --> d7
 - LPC2129 P0.16 --> RS
 - LPC2129 P0.17 --> R/W
 - LPC2129 P0.18 --> EN
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/1a6cace6-9098-47cb-bd17-f1887b209d0f)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 21 43_59bfae09](https://github.com/user-attachments/assets/9999a5e5-bbbe-4d6c-b8fa-a43ad058c967)

![WhatsApp Image 2025-06-03 at 15 21 43_ed4f7e64](https://github.com/user-attachments/assets/74f344ae-0af8-4cd5-9064-6656b439c01c)

![WhatsApp Image 2025-06-03 at 15 21 44_7dc85125](https://github.com/user-attachments/assets/941bcb7e-2c4a-4e3c-bca3-d3f99860167c)


__Project Code:__
```
//lcd_test.c
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
u8 cgramLUT[8]=
{0x07,0x04,0x04,0x1f,0x10,0x10,0x10,0x00};
main()
{
	InitLCD();
	BuildCGRAM(cgramLUT,8);
	
	CharLCD('A');
	StrLCD(" V24HE6 ");
	CmdLCD(GOTO_LINE2_POS0);
	U32LCD(1234567890);
	delay_ms(2000);
	CmdLCD(CLEAR_LCD);
	S32LCD(-1234567890);
	CmdLCD(GOTO_LINE2_POS0);
	F32LCD(123.456789,6);
	delay_ms(2000);
	CmdLCD(CLEAR_LCD);
	HexLCD(256);
	CmdLCD(GOTO_LINE2_POS0);
	OctLCD(65);
	delay_ms(1000);
	CmdLCD(CLEAR_LCD);	
	BinLCD(127,16);
	CmdLCD(GOTO_LINE2_POS0);
	CharLCD(0);
	while(1);
}
```
_____________________________________________________________________________________________________________________________________________________

__14. Title: Displaying Capital Alphabets with ASCII Values on 16x2 LCD__

*Objective:*\
To develop an Embedded C program that sequentially displays capital alphabets (A-Z) along with their ASCII values in both decimal and hexadecimal formats on a 16x2 LCD display. Each character and its corresponding ASCII values will be shown for 500ms before updating to the next character, ensuring continuous display from A to Z.

__Hardware Connection:__
 - LPC2129 P0.8 --> d0
 - LPC2129 P0.9 --> d1
 - LPC2129 P0.10 --> d2
 - LPC2129 P0.11 --> d3
 - LPC2129 P0.12 --> d4
 - LPC2129 P0.13 --> d5
 - LPC2129 P0.14 --> d6
 - LPC2129 P0.15 --> d7
 - LPC2129 P0.16 --> RS
 - LPC2129 P0.17 --> R/W
 - LPC2129 P0.18 --> EN
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/fe9ec1b9-a946-48cb-90df-d3e521d431b2)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 22 43_ab887f0b](https://github.com/user-attachments/assets/b0b47eb0-7aaa-4943-ae03-752336ccfaa0)

![WhatsApp Image 2025-06-03 at 15 22 43_5e580cc6](https://github.com/user-attachments/assets/f08f2bf2-7a0c-4218-92d1-eae117453cab)

![WhatsApp Image 2025-06-03 at 15 22 44_a8a1a057](https://github.com/user-attachments/assets/d8b31cf4-e0ea-4c89-96d7-314fbda60e25)


__Project Code:__
```
//alphabets_printing.c
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"

main()
{
    u32 i;  // Corrected 'u3' to 'u32' as data type
    InitLCD();  // Initialize LCD
    
    for(i = 0; i < 26; i++)  // Loop for 26 alphabets (A-Z)
    {
        CharLCD('A' + i);     // Display the alphabet
        CharLCD(' ');         // Add space for clarity
        
        U32LCD('A' + i);      // Display ASCII value in Decimal
        CharLCD(' ');         // Add space
        
        HexLCD('A' + i);      // Display ASCII value in Hexadecimal
        delay_ms(500);        // Delay for visibility
        
        CmdLCD(CLEAR_LCD);    // Clear LCD for next character display
    }
    while(1);  // Infinite loop to keep the program running
}
```

________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

__15. Title: Electronic Dice Simulation Using LCD Display__

*Objective:*\
To implement an embedded C program that simulates an electronic dice using an LPC21xx microcontroller. The program continuously displays the current dice face value (1-6) on a 16x2 LCD. When a button connected to pin P1.16 is pressed, a new random dice face value is generated and displayed. The system ensures randomness by updating the seed and introduces a small delay for stable operation.

__Hardware Connection:__
 - LPC2129 P0.8 --> d0
 - LPC2129 P0.9 --> d1
 - LPC2129 P0.10 --> d2
 - LPC2129 P0.11 --> d3
 - LPC2129 P0.12 --> d4
 - LPC2129 P0.13 --> d5
 - LPC2129 P0.14 --> d6
 - LPC2129 P0.15 --> d7
 - LPC2129 P0.16 --> RS
 - LPC2129 P0.17 --> R/W
 - LPC2129 P0.18 --> EN
 - LPC2129 P1.16 --> swich
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/fcd22dd7-c9a5-4bd8-b49b-a0ed1af71849)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 23 48_0f3d9272](https://github.com/user-attachments/assets/a3e491a5-7a6d-4728-8a2b-64abf2c05979)

![WhatsApp Image 2025-06-03 at 15 23 49_cae6e1fb](https://github.com/user-attachments/assets/dffdc4d1-4cd6-42ab-b68a-2a6387f0a066)

![WhatsApp Image 2025-06-03 at 15 23 49_6d1e54fd](https://github.com/user-attachments/assets/eee4c44d-563a-4849-a956-c688b22a41e5)


__Project Code:__
```
//electronics_dice_lcd.c
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
#include <stdlib.h>
#include <LPC21xx.h>

#define ROLL_SW 16 //@p1.16
main()
{
	u32 faceVal=0,seed=1;
	InitLCD();
	StrLCD("Electronic Dice");
	
	while(1)
	{
		CmdLCD(GOTO_LINE2_POS0);
		U32LCD(faceVal);
		if(((IOPIN1>>ROLL_SW)&1)==0)
		{
			faceVal=(rand()%6)+1;
			srand(++seed);
		  delay_ms(10); 	
		}
	}
}
```

_________________________________________________________________________________________________________________________________________________________________

__16. Title: Scrolling and Oscillating Message Display on LCD Using LPC2129__

Objective:
To implement a program that displays a scrolling and oscillating message ("GOPAL") on an LCD interfaced with an LPC21xx microcontroller. The message moves from left to right and then oscillates back from right to left continuously, demonstrating dynamic text movement on an LCD screen.

__Hardware Simulation:__
 - LPC2129 P0.8 --> d0
 - LPC2129 P0.9 --> d1
 - LPC2129 P0.10 --> d2
 - LPC2129 P0.11 --> d3
 - LPC2129 P0.12 --> d4
 - LPC2129 P0.13 --> d5
 - LPC2129 P0.14 --> d6
 - LPC2129 P0.15 --> d7
 - LPC2129 P0.16 --> RS
 - LPC2129 P0.17 --> R/W
 - LPC2129 P0.18 --> EN
 - LED --> GND

__Software Simulation:__

![image](https://github.com/user-attachments/assets/0a163201-5ba7-473c-95b7-933a9d6bb700)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 24 52_5653e36f](https://github.com/user-attachments/assets/7a626d21-67b1-49e7-8ea2-61530b9f30c1)

![WhatsApp Image 2025-06-03 at 15 24 52_6e4d1111](https://github.com/user-attachments/assets/9e5a4689-f547-46cd-af31-a46fd258b2a4)


__Project code:__
```
//msg_scrolling_oscillating.c
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
#include <LPC21xx.h>

s8 msg[]="GOPAL";
main()
{
	s32 i;
	InitLCD();
	
	while(1)
	{
		
		for(i=0;i<=16;i++)
		{
			CmdLCD(GOTO_LINE1_POS0+i);
			StrLCD(msg);
			delay_ms(100);
			CmdLCD(CLEAR_LCD);
		}
		for(i=15;i>=0;i--)
		{
			CmdLCD(GOTO_LINE1_POS0+i);
			StrLCD(msg);
			delay_ms(100);
			CmdLCD(CLEAR_LCD);
		}
		
	}
}
```

____________________________________________________________________________________________________________________________________________________________________________

__17. Title: Fastest Finger First Timer using LCD and LPC2129 Microcontroller__

*Objective:* The objective of this project is to develop a "Fastest Finger First" timer using an LCD display and an LPC21xx microcontroller. The system:

1. Displays a starting message on the LCD.
2. Waits for the trigger switch to be pressed to start the timer.
3. Continuously increments and displays the elapsed time in seconds and milliseconds.
4. Stops the timer when the stop switch is pressed and holds the final time on the display.
5. Resets for the next round after recording the reaction time.

__Hardware connection:__
 - LPC2129 P0.8 --> d0
 - LPC2129 P0.9 --> d1
 - LPC2129 P0.10 --> d2
 - LPC2129 P0.11 --> d3
 - LPC2129 P0.12 --> d4
 - LPC2129 P0.13 --> d5
 - LPC2129 P0.14 --> d6
 - LPC2129 P0.15 --> d7
 - LPC2129 P0.16 --> RS
 - LPC2129 P0.17 --> R/W
 - LPC2129 P0.18 --> EN
 - LPC2129 P1.16 --> switch 1
 - LPC2129 P1.17 --> switch 1
 - LPC2129 GND --> GND

__Software simulation:__

![image](https://github.com/user-attachments/assets/634e4f51-7d72-4b1d-ace0-49156f08663f)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 27 33_e8df56d6](https://github.com/user-attachments/assets/271ab3d4-a716-45fa-a46c-ec70e4f34974)

![WhatsApp Image 2025-06-03 at 15 27 33_230082ef](https://github.com/user-attachments/assets/37a84ee8-706d-4517-a5dc-cc32ec341399)

![WhatsApp Image 2025-06-03 at 15 27 34_8ae8320f](https://github.com/user-attachments/assets/09b4436a-fe5d-4763-896f-5a5759be7897)


__Project Code:__
```
// fastest_finger_first_lcd.c

#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
#include <stdlib.h>
#include <LPC21xx.h>

#define TRIG_SW_AL 16    // Trigger switch at P1.16
#define STOP_SW_AL 17    // Stop switch at P1.17

void disp_time(u32 sec, u32 millisec);

main()
{
    u32 millisec = 0, sec = 0, flag = 0;
    InitLCD();             // Initialize LCD
    StrLCD("Fast Finger 15+"); // Display initial text
    
    while (1)
    {
        disp_time(sec, millisec);

        if (((IOPIN1 >> TRIG_SW_AL) & 1) == 0)   // Trigger switch pressed
        {
            flag = 1;
            while (((IOPIN1 >> TRIG_SW_AL) & 1) == 0)
            {
                disp_time(sec, millisec);  // Keep displaying the time while pressed
            }

            while (flag == 1)
            {
                for (sec = 0; sec < 10; sec++)
                {
                    if (((IOPIN1 >> STOP_SW_AL) & 1) == 0)   // Stop switch pressed
                    {
                        flag = 2;
                        while (((IOPIN1 >> STOP_SW_AL) & 1) == 0)
                        {
                            disp_time(sec, millisec);  // Continue displaying during stop hold
                        }
                        break;
                    }

                    if (flag == 2)
                    {
                        flag = 3;
                        break;
                    }

                    if (flag == 3)
                    {
                        flag = 0; // Reset the flag for the next round
                        break;
                    }

                    // Increment the milliseconds to simulate timing
                    for (millisec = 0; millisec < 10; millisec++)
                    {
                        delay_ms(100);  // Simulate 100ms delay for each millisecond step
                        disp_time(sec, millisec);
                    }
                }
            }
        }
    }
}

// Function to Display Time on LCD
void disp_time(u32 sec, u32 millisec)
{
    CmdLCD(GOTO_LINE2_POS0); // Move cursor to line 2, position 0
    U32LCD(sec);             // Display seconds
    CharLCD('.');            // Decimal point
    U32LCD(millisec);        // Display milliseconds
}
```
________________________________________________________________________________________________________________________________________________________________________
__18.Title: Fastest Finger First System Using LPC2129 with 7-Segment Display__

*Objective:* To develop a Fastest Finger First system using the LPC2129 ARM7 microcontroller that measures and displays a participant’s reaction time. The system begins timing when a trigger switch is pressed and stops when the stop switch is activated. The elapsed time (in seconds and milliseconds) is displayed on a 4-digit multiplexed 7-segment display, simulating a game show-style buzzer system for capturing the fastest response time.

__Hardware Connection:__
 - LPC2129 P0.8 --> a
 - LPC2129 P0.9 --> b
 - LPC2129 P0.10 --> c
 - LPC2129 P0.11 --> d
 - LPC2129 P0.12 --> e
 - LPC2129 P0.13 --> f
 - LPC2129 P0.14 --> g
 - LPC2129 P0.15 --> dp
 - LPC2129 P1.16 --> active switch 1
 - LPC2129 P1.17 --> active switch 2

__Software Connection:__

![image](https://github.com/user-attachments/assets/9e1c6f60-afbf-427b-93fe-872d8049eab0)


__Project code:__
```
//fastest_finger_first.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg.h"
#define TRIG_SW_AL 16//p1.16
#define STOP_SW_AL 17//p1.17
main()
{
	u32 millisec=0,sec=0,flag;
	init_4_mux_segs();
	while(1)
	{	
		disp_time(sec,millisec);
		if(((IOPIN1>>TRIG_SW_AL)&1)==0)
		{
		 flag=1;	
     while(((IOPIN1>>TRIG_SW_AL)&1)==0)
     {
			 disp_time(sec,millisec);
     }
	  }	
		
		while(flag==1)
		{	
			for(sec=0;sec<10;sec++)
			{
			 for(millisec=0;millisec<1000;millisec+=4)
			 {
				disp_time(sec,millisec);
				if(((IOPIN1>>STOP_SW_AL)&1)==0)
		    {
		      flag=2;	
          while(((IOPIN1>>STOP_SW_AL)&1)==0)
          {
			     disp_time(sec,millisec);
					 break;	
          }
	      }
        if(flag==2)
        {
          flag=3;
          break;					
		    }
			 }
			 if(flag==3)
       {
          flag=0;
          break;					
		   }
			}
    }
  } 		
}
```

_________________________________________________________________________________________________________________________________________
__19. Title: 4x4 Matrix Keypad Interface and Display Test Using LPC2129 and LCD__

*objective:* To interface a 4x4 matrix keypad with the LPC2129 ARM7 microcontroller and display the key pressed on a 16x2 LCD. This project verifies the correct detection of key presses through a scanning method and demonstrates the real-time display of the pressed key’s code, helping in validating keypad functionality for embedded input systems.

__Hardware Connections:__\
Keypad connections: 

![image](https://github.com/user-attachments/assets/c4347693-b5e6-42a5-8e6f-3629d536a9aa)

Lcd Connections: 

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

__Software Simulation:__

![image](https://github.com/user-attachments/assets/685aa0f3-0a46-4ca3-84e2-62e18c0a5a6d)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 25 48_0c51ae0d](https://github.com/user-attachments/assets/a28c77f7-dfd8-436c-99a6-dc3461c1fc42)

![WhatsApp Image 2025-06-03 at 15 25 48_d619bfa7](https://github.com/user-attachments/assets/0a3803ac-dc72-45ae-8f48-4aafe28fd2f7)

__Project code:__
```
//kpm_test_1.c
#include <LPC21xx.H>
#include "types.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "kpm.h"
#include "delay.h"

main()  
{
    u32 key;  // Corrected variable declaration
    InitLCD(); // Initialize LCD
    InitKPM(); // Initialize Keypad Module

    // Display initial message
    StrLCD("4x4 KPM TEST"); 

    while(1) 
    {
        key = KeyScan(); // Corrected function call for key reading
        CmdLCD(GOTO_LINE2_POS0); // Move cursor to Line 2, Position 0
        StrLCD("                "); // Display "..."
        CmdLCD(GOTO_LINE2_POS0); // Reset cursor to Line 2, Position 0
        U32LCD(key);  // Display the key value on LCD
				delay_ms(100);
		while(ColScan()==0);
    }
}
```
________________________________________________________________________________________________________________________________
__20. Title: SMS-Style Text Entry Using 4x4 Keypad and LCD with LPC2129__

*objective:* To implement an SMS-style multi-tap text input system using a 4x4 matrix keypad and a 16x2 character LCD interfaced with the LPC2129 ARM7 microcontroller. The project emulates the input behavior of traditional mobile keypads where multiple characters are mapped to a single key. Each press within a short duration cycles through the associated characters, which are then displayed on the LCD.

__Hardware Connections:__\
Keypad connections: 

![image](https://github.com/user-attachments/assets/c4347693-b5e6-42a5-8e6f-3629d536a9aa)

Lcd Connections: 

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

__Software Simulation:__

![image](https://github.com/user-attachments/assets/685aa0f3-0a46-4ca3-84e2-62e18c0a5a6d)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 25 48_82128361](https://github.com/user-attachments/assets/cbc67aad-3907-405a-9de6-a39af838ca0c)

![WhatsApp Image 2025-06-03 at 15 25 48_d619bfa7](https://github.com/user-attachments/assets/0154a2a9-f343-4fd1-9c3e-44c9ae6ea61b)

__Project code:__
```
//sms_keypad_test.c
#include <LPC21xx.h>
#include "kpm.h"
#include "lcd.h"
#include "kpm_defines.h"
#include "lcd_defines.h"
#include "kpm.h"

extern s32 presskey, khcount;

int main()
{
    u32 dlyms = 250;
    s32 pos = -1;

    InitLCD();
		InitKPM();
    StrLCD("SMS Keypad");

    while(1)
    {
        khcount = -1;
        while (ColScan());

        for (dlyms = 12000 * 250; dlyms > 0; dlyms--);

        // Re-initialize all rows
        IOCLR1 = 0xF << ROW0;
        if (!ColScan())
        {
            if (khcount == 3)
            {
                khcount = -1;
            }
            else if (khcount == -1)
            {
                pos++;
                if (pos> 15)
                {
                    CmdLCD(GOTO_LINE2_POS0);
                    StrLCD("                ");
                    CmdLCD(GOTO_LINE2_POS0);
                    pos = 0;
                }
            }

            khcount++;
            presskey = KeyScan();
            CmdLCD(GOTO_LINE2_POS0 + pos);
            CharLCD(presskey);
            while (!ColScan());

            dlyms = 12000 * 250;
        }
    }
}
```
____________________________________________________________________________________________________________________________________________________________________________

__21. Title: ADC Value Display on LCD using LPC2129__

*objective:* To develop a test application that reads analog input values through the ADC channel of the LPC2129 microcontroller and displays both the digital ADC value and its equivalent analog voltage (in float format) on a 16x2 character LCD. This verifies the functionality of the ADC module and LCD interfacing in real-time.

__Hardware Conncections:__\
Lcd Connections: 

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

Potential Meter: Connect with LPC2129 P0.28

__Software Simulation:__

![image](https://github.com/user-attachments/assets/da369ff3-9d9a-490c-a287-72e6ce2d9f1c)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 29 41_9915b611](https://github.com/user-attachments/assets/a76cd3f4-f734-48fb-bc7b-840faa122f11)

__Project Code:__
```
//lcd_adc_test.c
#include "adc.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"
f32 eAR;
u32 adcVal;
main()
{
	InitLCD();
	Init_ADC();
	StrLCD("ADC TEST :");
	while(1)
	{
		Read_ADC(0,&adcVal,&eAR);
		CmdLCD(GOTO_LINE2_POS0);
		U32LCD(adcVal);
		CmdLCD(GOTO_LINE2_POS0+8);
		F32LCD(eAR,3);
		delay_ms(100);
		CmdLCD(GOTO_LINE2_POS0);
		StrLCD("                ");
	}	
}
```

_________________________________________________________________________________________________________________________________________________________________________________

__22.Title: Temperature Monitoring using LM35 Sensor and LPC2129 with LCD Display__

*Objective:* To interface an LM35 temperature sensor with the LPC2129 microcontroller and continuously monitor the ambient temperature. The analog output from the LM35 is read through the ADC, converted to a digital temperature value in degrees Celsius, and displayed on an LCD. This project demonstrates temperature sensing, ADC conversion, and LCD interfacing.

__Harwdare Connections:__\
lcd connections: 

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

lm35 connections:\
	- lm35 out ---> lpc2129 p0.27

 __Software Simulation:__

 ![image](https://github.com/user-attachments/assets/fa5288e7-dc50-43f3-ae82-cc0380cd3a5f)

__Hardware Simulation:__

![WhatsApp Image 2025-06-03 at 15 30 15_48271a27](https://github.com/user-attachments/assets/3967dd34-eb63-4e46-9f45-4a7d2874bdf3)

![WhatsApp Image 2025-06-03 at 15 30 15_d0f44fce](https://github.com/user-attachments/assets/eb6f7e62-4ae1-4f0d-ab0a-b9b431cd2014)


__Project Code:__
```
// lcd_adc_lm35_test.c
#include "lm35.h"
#include "adc.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"

main()
{
    InitLCD();                       // Initialize LCD
    StrLCD("LM35 TEST :");           // Display initial text on LCD

    while(1)
    {
        CmdLCD(GOTO_LINE2_POS0);     // Move cursor to second line, position 0
        U32LCD(Read_Temp());        // Display temperature value (in Celsius)
        StrLCD(" degC");             // Append "degC" text
    }
}

```

____________________________________________________________________________________________________________________________________________________________________________

__23.Title: Distance Measurement using GP2D12 Sensor with LPC2129 and LCD Display__

*Objective:* To interface the Sharp GP2D12 infrared distance sensor with the LPC2148 microcontroller and display the measured distance on an LCD. The analog output from the GP2D12 is read using the ADC, processed to obtain distance in centimeters, and continuously updated on the LCD. This project demonstrates real-time distance sensing and LCD data visualization using ADC. 

__Hardware Connection:__\
lcd Connection:

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

gp2d12 connections:\
	- gp2d12 out ---> lpc2129 p0.27

 __Software Simulation:__

 ![image](https://github.com/user-attachments/assets/cdd08899-d165-4032-afdc-890651093069)

__Project Code:__
```
//lcd_adc_gp2d12_test.c
#include "gp2d12.h"
#include "types.h"
#include "lcd.h"
#include "delay.h"
#include "lcd_defines.h"
main()
{
	InitLCD();
	StrLCD("GP2D12 TEST:");
	while(1)
	{
		CmdLCD(GOTO_LINE2_POS0);
		U32LCD(Read_GP2D12());
	}
}

```
______________________________________________________________________________________________________________________________________________

__24. Title: DHT11 Interfacing with LPC2129 for Temperature and Humidity Monitoring__

*Objective:* To interface the DHT11 digital temperature and humidity sensor with the LPC2129 ARM7 microcontroller, enabling real-time monitoring and display of environmental conditions (temperature in °C and humidity in %) on a character LCD. This project demonstrates single-wire communication, accurate timing using software delays, and embedded system integration of sensor modules with ARM-based microcontrollers.

__Hardware Connection:__\
lcd Connection:

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)

DHT11 connections:\
	- DHT11 out ---> lpc2129 p0.10

__Project Code:__
```
//dht11_test.c

#include <lpc21xx.h>
#include "dht11.h"
#include "delay.h"
#include "lcd.h"

int main() {
    u8 temperature, humidity;
		InitLCD();
    dht11_init();

    while (1) {
        dht11_read_data(&temperature, &humidity);
        CmdLCD(0x80);
        StrLCD("Temp: ");
        U32LCD(temperature);
        StrLCD(" C");

        CmdLCD(0xC0);
        StrLCD("Humidity: ");
        U32LCD(humidity);
        StrLCD(" %");

        delay_ms(2000);
    }
}
```

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________

__25. Title: 20x4 LCD Interface with LPC2129 for Multi-Format Data Display__

*Objcetive:* To interface a 20x4 alphanumeric LCD with the LPC2148 ARM7 microcontroller and demonstrate the display of various data types and formats including:
 - Characters and strings
 - Unsigned and signed integers
 - Floating-point numbers with configurable precision
 - Hexadecimal, octal, and binary values
 - Custom characters using CGRAM


__Hardware Connection:__\
lcd Connection:

![image](https://github.com/user-attachments/assets/c2aed01d-0a61-47e8-8472-fda7890923bb)


__Software Simulation:__

![image](https://github.com/user-attachments/assets/04d5f0c1-f762-41ae-a59d-79de7f41151e)

__Project Code:__
```
//lcd 20*4

#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
u8 cgramLUT[8]={0x07,0x04,0x04,0x1f,0x10,0x10,0x10,0x00};
main()
{
	InitLCD();
	BuildCGRAM(cgramLUT,8);
	
	CmdLCD(GOTO_LINE1_POS0);
	CharLCD('A');
	CmdLCD(GOTO_LINE1_POS0+5);
	StrLCD(" V24HE6 ");
	delay_ms(1000);
	
	CmdLCD(GOTO_LINE2_POS0);
	U32LCD(1234567890);
	delay_ms(1000);
	
	CmdLCD(GOTO_LINE3_POS0);
	S32LCD(-1234567890);
	delay_ms(1000);
	
	CmdLCD(GOTO_LINE4_POS0);
	F32LCD(123.456789,6);
	delay_ms(2000);
	
	CmdLCD(CLEAR_LCD);
	CmdLCD(GOTO_LINE1_POS0);
	HexLCD(256);
	delay_ms(1000);
	
	CmdLCD(GOTO_LINE2_POS0);
	OctLCD(65);
	delay_ms(1000);
	
	CmdLCD(GOTO_LINE3_POS0);
	BinLCD(127,16);
	delay_ms(1000);
		
	CmdLCD(GOTO_LINE4_POS0);
	CharLCD(0);
	delay_ms(1000);
	
	while(1);
}
```


_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
