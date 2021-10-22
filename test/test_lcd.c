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
// void test_LCD_init(){
//     LCD_Init();
//     int virtualPORTA = (int)PORTA;
//     TEST_ASSERT_EQUAL_HEX(0b00000000, PORTB);
    
//     TEST_ASSERT_EQUAL_HEX(virtualPORTA);
// }
void test_LCD_writeCommandInit4BitMode(){
    char init4bitMode = 0x20;
    
    LCD_WriteCommand(init4bitMode);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BIT_LOW(0b00100000, PORTB);

}
void test__LCD_writeCommand_5x8BitDisplay(){
    char cmd5x8display = 0x28;
    LCD_WriteCommand(cmd5x8display);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00001000, 0x08, PORTB);

}
void test__LCD_writeCommand_5x8BitDisplay_withPORTABitsHigh(){
    char cmd5x8display = 0x28;
    set_LCD_E();
    set_LCD_RW();
    LCD_WriteCommand(cmd5x8display);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00001000, 0x08, PORTB);

}
#endif // TEST
