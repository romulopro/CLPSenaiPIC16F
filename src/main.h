#ifndef MAIN_H
#define MAIN_H
#include<stdint.h>
int test_main(void);

// void InitApp(void);
// void ConfigureOscillator(void);

typedef enum {_9600 , _19200} baudrate;
typedef enum {ODD, EVEN, NO_PARITY} parity_options;
#endif // MAIN_H
