
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

void LCD_WriteMessage(const char* message){

    for(uint8_t ii = 0; message[ii]!='\0'; ii++){
        LCD_WriteData(message[ii]);
    }
}
//Initialize LCD in 4-bit mode
void LCD_Init(const char* endereco_modbus, const char* paridade, const char* baudrate){

    //send higher nibble
    __delay_ms(18);
    LCD_WriteCommand(SET_LCD_MODE_4BIT);
    LCD_WriteCommand(SET_LCD_MODE_4BIT_2LINES_5X8PIXEL);
    LCD_WriteCommand(CURSOR_ON_BLINK_OFF_DISPLAY_ON);
    LCD_WriteCommand(PUT_LCD_CURSOR_AT_HOME);
    LCD_WriteCommand(AUTO_INCREMENT_DISPLAY_RIGHT);
    /*At init, should display serial baud rate, modbus device address and parity
    */ 
   LCD_WriteCommand(CURSOR_AT_1ST_LINE);
   LCD_WriteMessage(endereco_modbus);
   LCD_WriteCommand(CURSOR_AT_2ND_LINE);
   LCD_WriteMessage(paridade);
   LCD_WriteCommand(INCREMENT_CURSOR_POSITION);
   LCD_WriteMessage(baudrate);

}
void LCD_WriteCommand(const char cmd){
    PORTB &= 0b11110000;
    PORTB |= ((cmd >> 4) & 0x0F);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    __delay_ms(2);
    LCD_E = 0;
    __delay_ms(4);
    //send lower nibble
    PORTB &= 0b11110000;
    PORTB |= (cmd & (0x0F));
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    __delay_ms(2);
    LCD_E = 0;
    __delay_ms(4);
    
}

void LCD_WriteData(const char dataToWrite){
    PORTB &= 0b11110000;
    PORTB |= ((dataToWrite >> 4) & 0x0F);
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    __delay_ms(1);
    LCD_E = 0;
    __delay_ms(1);
    //send lower nibble
    PORTB &= 0b11110000;
    PORTB |= (dataToWrite & (0x0F));
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    __delay_ms(1);
    LCD_E = 0;
    __delay_ms(1);
    return;
}

