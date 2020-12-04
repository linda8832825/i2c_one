//MASTER

#include "mcc_generated_files/mcc.h"
#include "ex.h"

#define I2C_SLAVE_ADDR                  8
#define DATA                            0x55

void main(void)
{
    uint8_t dataa =DATA;
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(100);
    
    I2C1_Writer(I2C_SLAVE_ADDR, dataa);
    
    
    while (1)
    {
     
//      __delay_ms(10);
    }
}

