/* 
 * File:   DS1307.h
 * Author: MOAAZ
 *
 * Created on May 19, 2024, 1:13 PM
 */

#ifndef DS1307_H
#define	DS1307_H
/* section include */
#include "../../MCAL_Layer/MSSP_I2C/hal_i2c.h"
/* section datatype declaration */
typedef struct{
    uint8 seconds;
    uint8 minutes ;
    uint8 hours  ;
    uint8 days ;
    uint8 months ;
    uint8 years ;
}DS1307_T;

/*Iinterfaces  section*/
DS1307_T Realtimeclock_DS1307(void);
#endif	/* DS1307_H */

