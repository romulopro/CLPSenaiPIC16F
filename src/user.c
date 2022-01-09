/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif
#ifdef TEST
//#include "stub_pic16f877a.h"
#endif
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"
#include "PetitModbus.h"
#include "lcd.h"
//#include <pic16f877a.h>
#define SETA_COMO_SAIDA_PORT 0
#define SETA_COMO_ENTRADA_PINOS_0_ATE_5_E_UART 0b10111111
#define ADRRESS_DEVICE 0
#define PARITY_EEPROM_ADDRESS 0x01
#define BAUDRATE_EEPROM_ADREESS 0x02

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{

    /* TODO Initialize User Ports/Peripherals/Project here */
    /* PORTD SAIDA DIGITAL */
    TRISD = SETA_COMO_SAIDA_PORT;
    PORTD = 0;

    TRISC = SETA_COMO_ENTRADA_PINOS_0_ATE_5_E_UART;
    
    /* PORTB DIRECAO DOS PINOS
    7 = Botao UP = in / 6 = Botao LEFT = in / 5 = Display RS = out / 4 = Botao RIGHT = in 
    3 = Display D7 = out / 2 = Display D6 = out / 1 = Display D5 = out / 0 = Display D4 = out */
    TRISB = 0b11010000;

    /*PORTA DIRECAO DOS PINOS 
    5 e 4 = Entrada Digital = out / RA3 = R/W DISPLAY = out
    RA2 = E DISPLAY = out / RA1 = BUZZER - out / RA0 = ************* = out*/
    TRISA = 0b00110000;

    /*PORTE DIRECAO DOS PINOS
    RE2 = BOTAO DOWN = in / RE1 = BOTAO ESC = in / RE0 = BOTAO ENTER = in / 
    */ 
    TRISE = 0b00000111;


    PORTD = 0xAA;
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    // Inicializando Timer 1 em 16-bit
    
    // T1CON,T1CKPS1 = 1;
    // T1CON,T1CKPS0 = 1;
    // T1CON,TMR1ON = 1;
    // T1CON = 0b00110001;
    // /* Enable interrupts */
    // //INTCON,T1CKPS1 = 1;
    // INTCON,GIE = 1;
    // INTCON,PEIE = 1;
    
    // PIE1,TMR1IE = 1;
        //Timer0 Registers Prescaler= 16 - TMR0 Preset = 0 - Freq = 244.14 Hz - Period = 0.004096 seconds
    OPTION_REGbits.T0CS = 0;  // bit 5  TMR0 Clock Source Select bit...0 = Internal Clock (CLKO) 1 = Transition on T0CKI pin
    OPTION_REGbits.T0SE = 0;  // bit 4 TMR0 Source Edge Select bit 0 = low/high 1 = high/low
    OPTION_REGbits.PSA = 0;   // bit 3  Prescaler Assignment bit...0 = Prescaler is assigned to the Timer0
    OPTION_REGbits.PS2 = 0;   // bits 2-0  PS2:PS0: Prescaler Rate Select bits
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 1;
    TMR0 = 0;             // preset for timer register


    // Interrupt Registers
    //INTCONbits.INTCON = 0x00;           // clear the interrpt control register
    INTCONbits.TMR0IE = 0;        // bit5 TMR0 Overflow Interrupt Enable bit...1 = Enables the TMR0 interrupt
    INTCONbits.TMR0IF = 0;        // bit2 clear timer 0 interrupt flag
    
    //getting_modbus_param_eeprom
    
/*     switch (bitrate)
    {
    case _9600:
        bitrate = _9600;
        break;
    case _19200:
        bitrate = _19200;
        break;
    default: // case _9600
        bitrate = _9600;
        break;
    } */

    
/*     switch(parity_modes){
        case ODD:
        parity_mode = ODD;
        break;
        case NO_PARITY:
        parity_mode = NO_PARITY;
        break;
        default: // even
        parity_mode = EVEN;
        break;
    } */

    //LCD_Init("01", "01", "9600");
    return;
}

