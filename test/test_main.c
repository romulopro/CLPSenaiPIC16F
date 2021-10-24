#ifdef TEST
#include "support/stub_pic16f877a.h"
//#include "mock_xc.h"
#include "main.h"


#include "unity.h"
#include "system.h"        /* System funct/params, like osc/peripheral config */
//#include "user.h"          /* User funct/params, such as InitApp */

//#include "system.h"

//int PORTB = 0;
//void InitApp();
void setUp(void)

{
    //void InitApp();
}

void tearDown(void)
{
}



void test_PORTDiniciaZero(){
    //PORTD = 0;
    PORTDbits.RD0 = 1;
    TEST_ASSERT_EQUAL_UINT8(PORTD, 1);
    
}



#endif // TEST
