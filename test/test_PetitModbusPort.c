#ifdef TEST

#include "support/stub_pic16f877a.h"
#include "unity.h"
#include "hal.h"
#include "lcd.h"
#include <mock_eeprom_routines.h>
#include "PetitModbus.h"
#include "PetitModbusPort.h"
//PETITMODBUS_SLAVE_ADDRESS = 04;
void setUp(void)
{
    PETITMODBUS_SLAVE_ADDRESS = 04;
}

void tearDown(void)
{
}

void test_PetitModbusPort_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement PetitModbusPort");
}

#endif // TEST
