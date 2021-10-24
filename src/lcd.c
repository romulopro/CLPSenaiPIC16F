

#include "lcd.h"
#include <stdint.h>
#include <stdbool.h>
#include "hal.h"
#ifdef TEST
#include "stub_pic16f877a.h"
#endif
//void set_RB5(void);
//RB0-3 -- DB4-7
#define LCD_RS PORTBbits.RB5
#define LCD_RW PORTAbits.RA3
#define LCD_E PORTAbits.RA2

// void set_LCD_RS(){
//     set_RB5();
//     return;
// }

// void clear_LCD_RS(){
//     clear_RB5();
// }

// void set_LCD_RW(){
//     set_RA3();
// }

// void clear_LCD_RW(){
//     clear_RA3();
// }
// void set_LCD_E(){
//     set_RA2();
// }

// void clear_LCD_E(){
//     clear_RA2();
// }

void LCD_writeMessage(){

}
//Initialize LCD in 4-bit mode
void LCD_Init(){

    //send higher nibble
    char virtualPORTB = 0;
    char SET_4BIT_OP = 0x20;
    PORTB |= ((SET_4BIT_OP >> 4) & 0x0F);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;
    //put 10x delay

    //send lower nibble
    PORTB |= (SET_4BIT_OP & (0x0F));
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;

    //put 10x delay
}
void LCD_WriteCommand(const char cmd){
    PORTB |= ((cmd >> 4) & 0x0F);
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;
    //put 10x delay

    //send lower nibble
    PORTB |= (cmd & (0x0F));
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;

    //put 10x delay
}

void LCD_WriteData(const char dataToWrite){
    PORTB &= 0x11110000;
    PORTB |= ((dataToWrite >> 4) & 0x0F);
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;
    //put 10x delay

    //send lower nibble
    PORTB &= 0x11110000;
    PORTB |= (dataToWrite & (0x0F));
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E = 1;
    //put x delay
    LCD_E = 0;

    //put 10x delay
    return;
}