#include "DS1307.h"
static DS1307_T DS1307;
static uint8 ack ; 
DS1307_T Realtimeclock_DS1307(void){
MSSP_I2c_read_data_Blocking(0x68 ,DS1307.seconds,ack);
MSSP_I2c_read_data_Blocking(0x69,DS1307.minutes,ack);
return DS1307 ; 
}
