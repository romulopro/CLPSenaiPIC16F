#ifndef LCD_H
#define LCD_H

#include "hal.h"
void set_LCD_RS(void);
void set_LCD_RS(void);

void clear_LCD_RS(void);

void set_LCD_RW(void);

void clear_LCD_RW(void);
void set_LCD_E(void);

void clear_LCD_E(void);
void LCD_Init(void);
void LCD_WriteCommand(char);
void LCD_WriteData(const char);
void LCD_WriteMessage(const char*);
#ifdef TEST
void __delay_ms(const uint16_t);
#endif
#endif // LCD_H
