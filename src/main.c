/*
 
 * Example 9-28, PIC and Embedded System
 
 */
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG




/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
//#define __XC
#ifdef TEST
//#include "stub_pic16f877a.h"
#endif
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif
#include "main.h"
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

#define _XTAL_FREQ 4000000L
//#include <pic16f877a.h>
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
#ifdef TEST

//PORTDbits_t PORTDbits.PORTD = 0;
// INTCON = {0X00};


int test_main(void)

#else
int main(void)
#endif
{
    /* Configure the oscillator for the device */
#ifndef TEST
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    PORTD = 0xAA;
    __delay_ms(500);
    PORTD = 0x55;
    __delay_ms(500);
    PORTD = 0xAA;
    __delay_ms(500);
    PORTD = 0x55;
    __delay_ms(500);
    PORTD = 0xAA;
    __delay_ms(500);
#else
    
    //int PORTD = 0;
#endif
    
    
    while(1)
    {
        /* TODO <INSERT USER APPLICATION CODE HERE> */
        
        //pisca_portd_leds_init();
        
        
    }

    return 0;

}

void pisca_portd_leds_init(){

    
}