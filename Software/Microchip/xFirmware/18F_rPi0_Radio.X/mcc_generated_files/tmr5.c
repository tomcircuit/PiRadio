/**
  TMR5 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr5.c

  @Summary
    This is the generated driver implementation file for the TMR5 driver using MPLAB® Code Configurator

  @Description
    This source file provides APIs for TMR5.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC18F44K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr5.h"

/**
  Section: Global Variable Definitions
*/
volatile uint16_t timer5ReloadVal;

/**
  Section: TMR5 APIs
*/

void TMR5_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T5SYNC do_not_synchronize; T5SOSCEN disabled; TMR5CS FOSC/4; TMR5ON disabled; T5RD16 disabled; T5CKPS 1:8; 
    T5CON = 0x34;

    //T5GPOL low; T5GSS T5G; T5GGO done; TMR5GE disabled; T5GSPM disabled; T5GTM disabled; T5GVAL disabled; 
    T5GCON = 0x00;

    //TMR5H 60; 
    TMR5H = 0x3C;

    //TMR5L 176; 
    TMR5L = 0xB0;

    // Load the TMR value to reload variable
    timer5ReloadVal=TMR5;

    // Clearing IF flag.
    PIR5bits.TMR5IF = 0;

    // Start TMR5
    TMR5_StartTimer();
}

void TMR5_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T5CONbits.TMR5ON = 1;
}

void TMR5_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T5CONbits.TMR5ON = 0;
}

uint16_t TMR5_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
    readValLow = TMR5L;
    readValHigh = TMR5H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR5_WriteTimer(uint16_t timerVal)
{
    if (T5CONbits.T5SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T5CONbits.TMR5ON = 0;

        // Write to the Timer5 register
        TMR5H = (timerVal >> 8);
        TMR5L = (uint8_t) timerVal;

        // Start the Timer after writing to the register
        T5CONbits.TMR5ON =1;
    }
    else
    {
        // Write to the Timer5 register
        TMR5H = (timerVal >> 8);
        TMR5L = (uint8_t) timerVal;
    }
}

void TMR5_Reload(void)
{
    // Write to the Timer5 register
    TMR5H = (timer5ReloadVal >> 8);
    TMR5L = (uint8_t) timer5ReloadVal;
}

void TMR5_StartSinglePulseAcquisition(void)
{
    T5GCONbits.T5GGO = 1;
}

uint8_t TMR5_CheckGateValueStatus(void)
{
    return T5GCONbits.T5GVAL;
}

bool TMR5_HasOverflowOccured(void)
{
    // check if  overflow has occurred by checking the TMRIF bit
    return(PIR5bits.TMR5IF);
}

/**
 End of File
*/
