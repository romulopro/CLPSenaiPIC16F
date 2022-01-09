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
#define __eeprom 
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
#include "lcd.h"
#include "PetitModbus.h"
#define _XTAL_FREQ 4000000L
//#include <pic16f877a.h>
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */
/* typedef enum {_9600 , _19200} baudrate;
typedef enum {ODD, EVEN, NO_PARITY} parity_options;
uint8_t PETITMODBUS_SLAVE_ADDRESS  = 1;
uint8_t PARITY = 1; //1 = ímpar
uint8_t BAUDRATE = _9600; //9600 */
//void ProcessPetitModbus(void);
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/


__eeprom uint8_t endereco_modbus = 0x02;
__eeprom uint8_t paridade = 0x01; // 1= impar, 2 = par, 3 no parity
__eeprom uint8_t bitrate = 0x01; // 1=9600 2= 19200
#ifdef TEST


int test_main(void)

#else
int main(void)
#endif
{
    /* Configure the oscillator for the device */
#ifndef TEST
    ConfigureOscillator();
    __delay_ms(1000);
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
    char dataToWrite[10] = "Gayola";
    LCD_WriteData(dataToWrite);
#else
    
    
#endif
    
    
    //ProcessPetitModbus();

    while(1)
    {
        /* TODO <INSERT USER APPLICATION CODE HERE> */
        
        //pisca_portd_leds_init();
        
        
    }

    return 0;

}