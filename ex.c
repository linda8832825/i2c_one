#include  "ex.h"
#include "mcc_generated_files/i2c1_master.h"

static i2c1_operations_t wr1RegCompleteHandlerer(void *ptr);

void I2C1_Writer(i2c1_address_t address, uint8_t data)
{
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(wr1RegCompleteHandlerer,&data);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
//    I2C1_Close();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

static i2c1_operations_t wr1RegCompleteHandlerer(void *ptr)
{
    I2C1_SetBuffer(ptr,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_CONTINUE;
}
