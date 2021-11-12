
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
#define CURSOR_AT_2ND_LINE 0xC0
#define CURSOR_AT_1ST_LINE 0xC0
#define INCREMENT_CURSOR_POSITION 0x07


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


    //put 10x delay
}
void LCD_WriteCommand(const char cmd){
    //PORTB &= 0x11110000;
    PORTB &= 0b11110000;
    PORTB |= ((cmd >> 4) & 0x0F);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;

    __delay_ms(2);
    LCD_E = 0;
    //put 10x delay
    __delay_ms(4);
    //send lower nibble
    PORTB &= 0b11110000;
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
    PORTB &= 0b11110000;
    PORTB |= ((dataToWrite >> 4) & 0x0F);
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    __delay_ms(1);
    LCD_E = 0;
    //put 10x delay
    __delay_ms(1);
    //send lower nibble
    PORTB &= 0b11110000;
    PORTB |= (dataToWrite & (0x0F));
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    __delay_ms(1);
    LCD_E = 0;
    __delay_ms(1);
    //put 10x delay
    return;
}

//send lower bits of the command to DS4_DS7 display pins
//void sendLowerNibble 
#ifdef TEST
void __delay_ms(const uint16_t time){
    return;
}
// unsigned char eeprom_read(const unsigned char address){
//     return 03;
// }
#endif