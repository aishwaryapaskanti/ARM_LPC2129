//pin_connect_block.c
#include "types.h"
#include <LPC21xx.h>
void CfgPortPinFunc(u32 portNo,u32 pinNo,u32 pinF)
{
 if(portNo==0)
 {	
   if((pinNo>=0)&&(pinNo<=15))	 
    PINSEL0=((PINSEL0&~(3<<(pinNo*2)))|
	          (pinF<<(pinNo*2))); 		
	 else if((pinNo>=16)&&(pinNo<=31))
    PINSEL1=((PINSEL1&~(3<<((pinNo-16)*2)))|
	          (pinF<<((pinNo-16)*2))); 
 }
 /*else if(portNo==1)
 {
   Not Required as all pins have ONLY one function
 }	
 */ 
}	
