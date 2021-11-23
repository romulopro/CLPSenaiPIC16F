#ifndef LCD_H
#define LCD_H


#ifdef TEST
#include "stub_pic16f877a.h"
#endif

void set_LCD_RS(void);
void set_LCD_RS(void);
void clear_LCD_RS(void);
void set_LCD_RW(void);
void clear_LCD_RW(void);
void set_LCD_E(void);
void clear_LCD_E(void);
void LCD_Init(const char*, const char*, const char*);
void LCD_WriteCommand(char);
void LCD_WriteData(const char);
void LCD_WriteMessage(const char*);

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
#endif // LCD_H
