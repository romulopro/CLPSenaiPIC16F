#ifdef TEST
#include "support/stub_pic16f877a.h"
#include "unity.h"
#include "hal.h"
#include "lcd.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_lcd_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement lcd");
}
void test_lcd_habilitaEscrita(){
    set_LCD_RS();
    //PORTBbits.RB1 = 1;
    //PORTC = 0;
    // PORTAbits.RA0 = 0;
    // PORTE = 0;
    TEST_ASSERT_EQUAL_CHAR(PORTB, 0b00100000);
}
void test_LCD_init(){
    LCD_Init();
    int virtualPORTA = (int)PORTA;
    TEST_ASSERT_EQUAL_HEX(0b00100000, PORTB);
    
    TEST_ASSERT_EQUAL_HEX(virtualPORTA, 0b00001000);
}
#endif // TEST
