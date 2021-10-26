
#ifdef TEST
#include "stub_pic16f877a.h"

#else
#include <xc.h>
#define _XTAL_FREQ 4000000L
#endif
#include "lcd.h"
#include <stdint.h>
#include <stdbool.h>
#include "hal.h"

//void set_RB5(void);
//RB0-3 -- DB4-7
#define LCD_RS PORTBbits.RB5
#define LCD_RW PORTAbits.RA3
#define LCD_E PORTAbits.RA2
#define SET_LCD_MODE_4BIT 0x20
#define SET_LCD_MODE_4BIT_2LINES_5X8PIXEL 0x28
#define CURSOR_ON_BLINK_OFF_DISPLAY_ON 0x0E
#define PUT_LCD_CURSOR_AT_HOME 0x02
#define AUTO_INCREMENT_DISPLAY_RIGHT 0x06


void LCD_WriteMessage(const char* message){

    for(uint8_t ii = 0; message[ii]!='\0'; ii++){
        LCD_WriteData(message[ii]);
    }
}
//Initialize LCD in 4-bit mode
void LCD_Init(){

    //send higher nibble
    __delay_ms(18);
    LCD_WriteCommand(SET_LCD_MODE_4BIT);
    LCD_WriteCommand(SET_LCD_MODE_4BIT_2LINES_5X8PIXEL);
    LCD_WriteCommand(CURSOR_ON_BLINK_OFF_DISPLAY_ON);
    LCD_WriteCommand(PUT_LCD_CURSOR_AT_HOME);
    LCD_WriteCommand(AUTO_INCREMENT_DISPLAY_RIGHT);
    /*At init, should display serial baud rate, modbus device address and parity
    */ 



    //put 10x delay
}
void LCD_WriteCommand(const char cmd){
    //PORTB &= 0x11110000;
    PORTBbits.RB3 = 0;
    PORTBbits.RB2 = 0;
    PORTBbits.RB1 = 0;
    PORTBbits.RB0 = 0;
    PORTB |= ((cmd >> 4) & 0x0F);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
//    if(TMR1IF == 0){
//        TMR1IF = 1;
//        TMR1 = 0x40;
//        return;
//    }else if(TMR1IE == 0){
//        return;
//    }
    __delay_ms(2);
    LCD_E = 0;
    //put 10x delay
    __delay_ms(4);
    //send lower nibble
    PORTB = PORTB & 0x11110000;
    PORTB |= (cmd & (0x0F));
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    __delay_ms(2);
    LCD_E = 0;
    __delay_ms(4);
    //put 10x delay
}

void LCD_WriteData(const char dataToWrite){
    PORTB &= 0x11110000;
    PORTB |= ((dataToWrite >> 4) & 0x0F);
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    __delay_ms(2);
    LCD_E = 0;
    //put 10x delay
    __delay_ms(4);
    //send lower nibble
    PORTB &= 0x11110000;
    PORTB |= (dataToWrite & (0x0F));
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    __delay_ms(2);
    LCD_E = 0;
    __delay_ms(4);
    //put 10x delay
    return;
}


#ifdef TEST
void __delay_ms(const uint16_t time){
    return;
}
#endif