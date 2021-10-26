#ifdef TEST
#include "support/stub_pic16f877a.h"
#include "unity.h"
#include "hal.h"
#include "lcd.h"

#define LCD_RS PORTBbits.RB5
#define LCD_RW PORTAbits.RA3
#define LCD_E PORTAbits.RA2

void setUp(void)
{
}

void tearDown(void)
{
}


void test_lcd_habilitaEscrita(){
    LCD_RS = 1;
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
    LCD_E = 1;
    LCD_RW = 1;
    LCD_WriteCommand(cmd5x8display);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00001000, 0x08, PORTB);

}
void test__LCD_writeDataCharacterW(){
    char toWrite = 0x47; // 'W'
    PORTB = 0x55;
    LCD_WriteData(toWrite);
    TEST_ASSERT_BITS(0b00101111, 0x27, PORTB);
}
void test__LCD_whenPORTBis255SendCharacter_thenPORTBLSBIs0x9(){
    char toWrite = 0x59;// 'Y'
    PORTB = 0xFF;
    LCD_WriteData(toWrite);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00101111, 0x29, PORTB);
}
void test__LCD_write2CharOnFirstLineDisplay(){
    char* twoLetters = "Oe";
    LCD_WriteMessage(twoLetters);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00101111, 0x25, PORTB);
}
void test__LCD_write3CharOnFirstLineDisplay(){
    char* threeLetters = "ZAZ";
    LCD_WriteMessage(threeLetters);
    TEST_ASSERT_BITS_LOW(0b00001100, PORTA);
    TEST_ASSERT_BITS(0b00101111, 0x2A, PORTB);
}


#endif // TEST
