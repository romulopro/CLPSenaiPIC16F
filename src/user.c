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
//#include <pic16f877a.h>
#define SETA_COMO_SAIDA_PORT 0
#define SETA_COMO_ENTRADA_PINOS_0_ATE_5_E_UART 0b10111111
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
    
    
}

