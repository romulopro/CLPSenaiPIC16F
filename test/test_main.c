#ifdef TEST
#include "support/stub_pic16f877a.h"
#include "mock_xc.h"
#include "main.h"


#include "unity.h"
#include "system.h"        /* System funct/params, like osc/peripheral config */
//#include "user.h"          /* User funct/params, such as InitApp */

//#include "system.h"

#include "main.h"
//int PORTB = 0;
//void InitApp();
void setUp(void)

{
    //void InitApp();
}

void tearDown(void)
{
}

void test_main_NeedToImplement(void)
{
    //test_main();
    TEST_IGNORE_MESSAGE("Need to Implement main");
}

void test_PORTDiniciaZero(){
    
    
    
}

// void test_interrupcaoGEIEHabilitada(){
//     void InitApp();
//     GIE = 0;
//     //printf("%d", INTCON);
//     TEST_ASSERT_BITS_HIGH(0x00FF, INTCON);
// }

#endif // TEST
