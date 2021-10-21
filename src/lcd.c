

#include "lcd.h"
#include <stdint.h>
#include <stdbool.h>
#include "hal.h"
//void set_RB5(void);
//RB0-3 -- DB4-7
void set_LCD_RS(){
    set_RB5();
    return;
}

void clear_LCD_RS(){
    clear_RB5();
}

void set_LCD_RW(){
    set_RA3();
}

void clear_LCD_RW(){
    clear_RA3();
}
void set_LCD_E(){
    set_RA2();
}

void clear_LCD_E(){
    clear_RA2();
}

void LCD_writeMessage(){

}
//Initialize LCD in 4-bit mode
void LCD_Init(){

    //send higher nibble
    char virtualPORTB = 0;
    char SET_4BIT_OP = 0x20;
    virtualPORTB = SET_4BIT_OP & 0x0F;
    writePORTB(virtualPORTB);
    clear_LCD_RS();
    clear_LCD_RW();
    set_LCD_E();
    //put x delay
    clear_LCD_E();
    //put 10x delay

    //send lower nibble
    virtualPORTB = SET_4BIT_OP & (0x0F << 4);
    clear_LCD_RS();
    clear_LCD_RW();
    set_LCD_E();
    //put x delay
    clear_LCD_E();

    //put 10x delay
}