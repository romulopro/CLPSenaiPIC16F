#ifndef LCD_H
#define LCD_H

#include "hal.h"
extern void set_LCD_RS(void);
void set_LCD_RS(void);

void clear_LCD_RS(void);

void set_LCD_RW(void);

void clear_LCD_RW(void);
void set_LCD_E(void);

void clear_LCD_E(void);
#endif // LCD_H
