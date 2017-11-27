/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC18F45K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X 2.26
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_TUNE aliases
#define channel_TUNE_TRIS               TRISA0
#define channel_TUNE_LAT                LATA0
#define channel_TUNE_PORT               PORTAbits.RA0
#define channel_TUNE_ANS                ANSA0
#define channel_TUNE_SetHigh()    do { LATA0 = 1; } while(0)
#define channel_TUNE_SetLow()   do { LATA0 = 0; } while(0)
#define channel_TUNE_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define channel_TUNE_GetValue()         PORTAbits.RA0
#define channel_TUNE_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define channel_TUNE_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define channel_TUNE_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define channel_TUNE_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set channel_BAND aliases
#define channel_BAND_TRIS               TRISA1
#define channel_BAND_LAT                LATA1
#define channel_BAND_PORT               PORTAbits.RA1
#define channel_BAND_ANS                ANSA1
#define channel_BAND_SetHigh()    do { LATA1 = 1; } while(0)
#define channel_BAND_SetLow()   do { LATA1 = 0; } while(0)
#define channel_BAND_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define channel_BAND_GetValue()         PORTAbits.RA1
#define channel_BAND_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define channel_BAND_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define channel_BAND_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define channel_BAND_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set channel_VOL aliases
#define channel_VOL_TRIS               TRISA2
#define channel_VOL_LAT                LATA2
#define channel_VOL_PORT               PORTAbits.RA2
#define channel_VOL_ANS                ANSA2
#define channel_VOL_SetHigh()    do { LATA2 = 1; } while(0)
#define channel_VOL_SetLow()   do { LATA2 = 0; } while(0)
#define channel_VOL_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define channel_VOL_GetValue()         PORTAbits.RA2
#define channel_VOL_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define channel_VOL_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define channel_VOL_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define channel_VOL_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set T0CKI aliases
#define T0CKI_TRIS               TRISA4
#define T0CKI_LAT                LATA4
#define T0CKI_PORT               PORTAbits.RA4
#define T0CKI_SetHigh()    do { LATA4 = 1; } while(0)
#define T0CKI_SetLow()   do { LATA4 = 0; } while(0)
#define T0CKI_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define T0CKI_GetValue()         PORTAbits.RA4
#define T0CKI_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define T0CKI_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

// get/set D_LED aliases
#define D_LED_TRIS               TRISC0
#define D_LED_LAT                LATC0
#define D_LED_PORT               PORTCbits.RC0
#define D_LED_SetHigh()    do { LATC0 = 1; } while(0)
#define D_LED_SetLow()   do { LATC0 = 0; } while(0)
#define D_LED_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define D_LED_GetValue()         PORTCbits.RC0
#define D_LED_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define D_LED_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set D_PIXEL aliases
#define D_PIXEL_TRIS               TRISC1
#define D_PIXEL_LAT                LATC1
#define D_PIXEL_PORT               PORTCbits.RC1
#define D_PIXEL_SetHigh()    do { LATC1 = 1; } while(0)
#define D_PIXEL_SetLow()   do { LATC1 = 0; } while(0)
#define D_PIXEL_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define D_PIXEL_GetValue()         PORTCbits.RC1
#define D_PIXEL_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define D_PIXEL_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set D_BEEP aliases
#define D_BEEP_TRIS               TRISC2
#define D_BEEP_LAT                LATC2
#define D_BEEP_PORT               PORTCbits.RC2
#define D_BEEP_ANS                ANSC2
#define D_BEEP_SetHigh()    do { LATC2 = 1; } while(0)
#define D_BEEP_SetLow()   do { LATC2 = 0; } while(0)
#define D_BEEP_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define D_BEEP_GetValue()         PORTCbits.RC2
#define D_BEEP_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define D_BEEP_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define D_BEEP_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define D_BEEP_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set channel_PI5V aliases
#define channel_PI5V_TRIS               TRISC3
#define channel_PI5V_LAT                LATC3
#define channel_PI5V_PORT               PORTCbits.RC3
#define channel_PI5V_ANS                ANSC3
#define channel_PI5V_SetHigh()    do { LATC3 = 1; } while(0)
#define channel_PI5V_SetLow()   do { LATC3 = 0; } while(0)
#define channel_PI5V_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define channel_PI5V_GetValue()         PORTCbits.RC3
#define channel_PI5V_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define channel_PI5V_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define channel_PI5V_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define channel_PI5V_SetDigitalMode()   do { ANSC3 = 0; } while(0)
// get/set D_PI27 aliases
#define D_PI27_TRIS               TRISC4
#define D_PI27_LAT                LATC4
#define D_PI27_PORT               PORTCbits.RC4
#define D_PI27_ANS                ANSC4
#define D_PI27_SetHigh()    do { LATC4 = 1; } while(0)
#define D_PI27_SetLow()   do { LATC4 = 0; } while(0)
#define D_PI27_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define D_PI27_GetValue()         PORTCbits.RC4
#define D_PI27_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define D_PI27_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define D_PI27_SetAnalogMode()   do { ANSC4 = 1; } while(0)
#define D_PI27_SetDigitalMode()   do { ANSC4 = 0; } while(0)
// get/set D_AUX aliases
#define D_AUX_TRIS               TRISC5
#define D_AUX_LAT                LATC5
#define D_AUX_PORT               PORTCbits.RC5
#define D_AUX_ANS                ANSC5
#define D_AUX_SetHigh()    do { LATC5 = 1; } while(0)
#define D_AUX_SetLow()   do { LATC5 = 0; } while(0)
#define D_AUX_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define D_AUX_GetValue()         PORTCbits.RC5
#define D_AUX_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define D_AUX_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define D_AUX_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define D_AUX_SetDigitalMode()   do { ANSC5 = 0; } while(0)
// get/set TX1 aliases
#define TX1_TRIS               TRISC6
#define TX1_LAT                LATC6
#define TX1_PORT               PORTCbits.RC6
#define TX1_ANS                ANSC6
#define TX1_SetHigh()    do { LATC6 = 1; } while(0)
#define TX1_SetLow()   do { LATC6 = 0; } while(0)
#define TX1_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define TX1_GetValue()         PORTCbits.RC6
#define TX1_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define TX1_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define TX1_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define TX1_SetDigitalMode()   do { ANSC6 = 0; } while(0)
// get/set RX1 aliases
#define RX1_TRIS               TRISC7
#define RX1_LAT                LATC7
#define RX1_PORT               PORTCbits.RC7
#define RX1_ANS                ANSC7
#define RX1_SetHigh()    do { LATC7 = 1; } while(0)
#define RX1_SetLow()   do { LATC7 = 0; } while(0)
#define RX1_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define RX1_GetValue()         PORTCbits.RC7
#define RX1_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define RX1_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define RX1_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define RX1_SetDigitalMode()   do { ANSC7 = 0; } while(0)
// get/set D_SW5V aliases
#define D_SW5V_TRIS               TRISD2
#define D_SW5V_LAT                LATD2
#define D_SW5V_PORT               PORTDbits.RD2
#define D_SW5V_ANS                ANSD2
#define D_SW5V_SetHigh()    do { LATD2 = 1; } while(0)
#define D_SW5V_SetLow()   do { LATD2 = 0; } while(0)
#define D_SW5V_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define D_SW5V_GetValue()         PORTDbits.RD2
#define D_SW5V_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define D_SW5V_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define D_SW5V_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define D_SW5V_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set D_PI17 aliases
#define D_PI17_TRIS               TRISD3
#define D_PI17_LAT                LATD3
#define D_PI17_PORT               PORTDbits.RD3
#define D_PI17_ANS                ANSD3
#define D_PI17_SetHigh()    do { LATD3 = 1; } while(0)
#define D_PI17_SetLow()   do { LATD3 = 0; } while(0)
#define D_PI17_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define D_PI17_GetValue()         PORTDbits.RD3
#define D_PI17_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define D_PI17_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define D_PI17_SetAnalogMode()   do { ANSD3 = 1; } while(0)
#define D_PI17_SetDigitalMode()   do { ANSD3 = 0; } while(0)
// get/set channel_PI3V aliases
#define channel_PI3V_TRIS               TRISD5
#define channel_PI3V_LAT                LATD5
#define channel_PI3V_PORT               PORTDbits.RD5
#define channel_PI3V_ANS                ANSD5
#define channel_PI3V_SetHigh()    do { LATD5 = 1; } while(0)
#define channel_PI3V_SetLow()   do { LATD5 = 0; } while(0)
#define channel_PI3V_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define channel_PI3V_GetValue()         PORTDbits.RD5
#define channel_PI3V_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define channel_PI3V_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define channel_PI3V_SetAnalogMode()   do { ANSD5 = 1; } while(0)
#define channel_PI3V_SetDigitalMode()   do { ANSD5 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/