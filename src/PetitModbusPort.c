//#include "General.h"
#ifdef TEST
#include "support/stub_pic16f877a.h"
#include "lcd.h"
#include <stdint.h>
#define TRMT TXSTAbits.TRMT


uint8_t TXREG;
uint8_t RCREG;
uint8_t TMR0;


#endif
#define TMR0_1_5char_timer_at_9600kbps 148
#include "PetitModbus.h"
#include "PetitModbusPort.h"

// This port file for PIC microcontrollers!

// Modbus RTU Variables
volatile unsigned char   PetitReceiveBuffer[PETITMODBUS_RECEIVE_BUFFER_SIZE];   // Buffer to collect data from hardware
volatile unsigned char   PetitReceiveCounter=0;                                 // Collected data number

// UART Initialize for Microconrollers, yes you can use another phsycal layer!
void PetitModBus_UART_Initialise(void)
{
// Insert UART Init Code Here
    //InitUART();
    //SPBRG @ 4MHz BRGH(1) = 19200 is 12 and 9600 is 25
    //Reception RCSTAbits
    RCSTAbits.SPEN = 1;
    RCSTAbits.RX9 = 1;
    RCSTAbits.CREN = 0;
    RCSTAbits.ADDEN = 0;
    //Transmission TXSTA
    TXSTAbits.TX9 = 1;
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    TXSTAbits.BRGH = 1;





}

// Timer Initialize for Petit Modbus, 1ms Timer will be good for us!
void PetitModBus_TIMER_Initialise(void)
{
    //1ms @ 4MHz
// Insert TMR Init Code Here
    __delay_ms(1);
    //InitTMR1();
}

// This is used for send one character
void PetitModBus_UART_Putch(unsigned char c)
{
	while(!TRMT);
	TXREG = c;
}

// This is used for send string, better to use DMA for it ;)
unsigned char PetitModBus_UART_String(unsigned char *s, unsigned int Length)
{
    unsigned short  DummyCounter;
    
    for(DummyCounter=0;DummyCounter<Length;DummyCounter++)
        PetitModBus_UART_Putch(s[DummyCounter]);
    
    return TRUE;
}

/*************************Interrupt Fonction Slave*****************************/
// Call this function into your UART Interrupt. Collect data from it!
// Better to use DMA
void ReceiveInterrupt(unsigned char Data)
{
    PetitReceiveBuffer[PetitReceiveCounter] = RCREG;
    PetitReceiveCounter++;

    if(PetitReceiveCounter>PETITMODBUS_RECEIVE_BUFFER_SIZE)  
        PetitReceiveCounter=0;

    //For 9600, t1.5 = 148, t3.5 = 4.02ms = 4 for timer0
    TMR0IF = 0;
    TMR0 = TMR0_1_5char_timer_at_9600kbps; // colocar valor do timer0/1/2 aqui
    
}

// Call this function into 1ms Interrupt or Event!
// void PetitModBus_TimerValues(void)
// {
//     PetitModbusTimerValue++;
// }
/******************************************************************************/

