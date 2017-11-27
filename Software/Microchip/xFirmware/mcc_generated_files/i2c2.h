/**
  MSSP2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c2.h

  @Summary
    This is the generated header file for the MSSP2 driver using MPLAB� Code Configurator

  @Description
    This header file provides APIs for driver for MSSP2.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.10.3
        Device            :  PIC18F45K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB 	          :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#ifndef _I2C2_H
#define _I2C2_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  I2C Slave Driver Status

  @Summary
    Defines the different status that the slave driver has
    detected over the i2c bus.

  @Description
    This defines the different status that the slave driver has
    detected over the i2c bus. The status is passed to the
    I2C2_StatusCallback() callback function that is implemented by
    the user of the slave driver as a parameter to inform the user
    that there was a change in the status of the driver due to
    transactions on the i2c bus. User of the slave driver can use these
    to manage the read or write buffers.

 */

typedef enum
{
    I2C2_SLAVE_WRITE_REQUEST,
    I2C2_SLAVE_READ_REQUEST,
    I2C2_SLAVE_WRITE_COMPLETED,
    I2C2_SLAVE_READ_COMPLETED,
} I2C2_SLAVE_DRIVER_STATUS;

#define I2C2_SLAVE_DEFAULT_ADDRESS          8

/**
    @Summary
        Initializes and enables the i2c slave instance : 2

    @Description
        This routine initializes the i2c slave driver instance for : 2
        index, making it ready for clients to open and use it.

    @Preconditions
        None

    @Param
        None

    @Returns
        None

    @Example
        <code>
            // initialize the i2c slave driver
            I2C2_Initialize();

        </code>
*/

void I2C2_Initialize(void);

/**
   @Summary
        This function process the I2C interrupts generated by
        bus activity

    @Description
        This function calls a callback function with 1 of 4
        possible parameters.
            I2C2_SLAVE_WRITE_REQUEST
            I2C2_SLAVE_READ_REQUEST
            I2C2_SLAVE_WRITE_COMPLETED
            I2C2_SLAVE_READ_COMPLETED

        The callback function should contain application specific
        code to process I2C bus activity from the I2C master.
        A basic EEPROM emulator is provided as an example.
 */

void I2C2_ISR ( void );

/**
   @Summary
        This varible contains the last data written to the I2C slave
*/

extern volatile uint8_t    I2C2_slaveWriteData;


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _I2C2_H