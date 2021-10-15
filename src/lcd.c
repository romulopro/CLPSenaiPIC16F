

#include "lcd.h"
#include <stdint.h>
#include <stdbool.h>
#include "hal.h"
//void set_RB5(void);

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
