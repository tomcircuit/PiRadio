/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26.1
        Device            :  PIC18F44K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

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
#define channel_TUNE_TRIS               TRISAbits.TRISA0
#define channel_TUNE_LAT                LATAbits.LATA0
#define channel_TUNE_PORT               PORTAbits.RA0
#define channel_TUNE_ANS                ANSELAbits.ANSA0
#define channel_TUNE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_TUNE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_TUNE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_TUNE_GetValue()           PORTAbits.RA0
#define channel_TUNE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_TUNE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_TUNE_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_TUNE_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_BAND aliases
#define channel_BAND_TRIS               TRISAbits.TRISA1
#define channel_BAND_LAT                LATAbits.LATA1
#define channel_BAND_PORT               PORTAbits.RA1
#define channel_BAND_ANS                ANSELAbits.ANSA1
#define channel_BAND_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_BAND_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_BAND_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_BAND_GetValue()           PORTAbits.RA1
#define channel_BAND_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_BAND_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_BAND_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define channel_BAND_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set channel_VOL aliases
#define channel_VOL_TRIS               TRISAbits.TRISA2
#define channel_VOL_LAT                LATAbits.LATA2
#define channel_VOL_PORT               PORTAbits.RA2
#define channel_VOL_ANS                ANSELAbits.ANSA2
#define channel_VOL_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_VOL_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_VOL_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_VOL_GetValue()           PORTAbits.RA2
#define channel_VOL_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_VOL_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_VOL_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define channel_VOL_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)

// get/set Q_LED aliases
#define Q_LED_TRIS               TRISCbits.TRISC0
#define Q_LED_LAT                LATCbits.LATC0
#define Q_LED_PORT               PORTCbits.RC0
#define Q_LED_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Q_LED_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Q_LED_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Q_LED_GetValue()           PORTCbits.RC0
#define Q_LED_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Q_LED_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set Q_PIXEL aliases
#define Q_PIXEL_TRIS               TRISCbits.TRISC1
#define Q_PIXEL_LAT                LATCbits.LATC1
#define Q_PIXEL_PORT               PORTCbits.RC1
#define Q_PIXEL_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Q_PIXEL_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Q_PIXEL_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Q_PIXEL_GetValue()           PORTCbits.RC1
#define Q_PIXEL_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Q_PIXEL_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set Q_BEEP aliases
#define Q_BEEP_TRIS               TRISCbits.TRISC2
#define Q_BEEP_LAT                LATCbits.LATC2
#define Q_BEEP_PORT               PORTCbits.RC2
#define Q_BEEP_ANS                ANSELCbits.ANSC2
#define Q_BEEP_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Q_BEEP_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Q_BEEP_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Q_BEEP_GetValue()           PORTCbits.RC2
#define Q_BEEP_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Q_BEEP_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Q_BEEP_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define Q_BEEP_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set channel_PI5V aliases
#define channel_PI5V_TRIS               TRISCbits.TRISC3
#define channel_PI5V_LAT                LATCbits.LATC3
#define channel_PI5V_PORT               PORTCbits.RC3
#define channel_PI5V_ANS                ANSELCbits.ANSC3
#define channel_PI5V_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define channel_PI5V_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define channel_PI5V_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define channel_PI5V_GetValue()           PORTCbits.RC3
#define channel_PI5V_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define channel_PI5V_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define channel_PI5V_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define channel_PI5V_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set Q_PI27 aliases
#define Q_PI27_TRIS               TRISCbits.TRISC4
#define Q_PI27_LAT                LATCbits.LATC4
#define Q_PI27_PORT               PORTCbits.RC4
#define Q_PI27_ANS                ANSELCbits.ANSC4
#define Q_PI27_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Q_PI27_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Q_PI27_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Q_PI27_GetValue()           PORTCbits.RC4
#define Q_PI27_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Q_PI27_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Q_PI27_SetAnalogMode()  do { ANSELCbits.ANSC4 = 1; } while(0)
#define Q_PI27_SetDigitalMode() do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set Q_AUX aliases
#define Q_AUX_TRIS               TRISCbits.TRISC5
#define Q_AUX_LAT                LATCbits.LATC5
#define Q_AUX_PORT               PORTCbits.RC5
#define Q_AUX_ANS                ANSELCbits.ANSC5
#define Q_AUX_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Q_AUX_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Q_AUX_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Q_AUX_GetValue()           PORTCbits.RC5
#define Q_AUX_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Q_AUX_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Q_AUX_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define Q_AUX_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()    do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()   do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()   do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()         PORTDbits.RD0
#define RD0_SetDigitalInput()   do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()  do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetAnalogMode() do { ANSELDbits.ANSD0 = 1; } while(0)
#define RD0_SetDigitalMode()do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()    do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()   do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()   do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()         PORTDbits.RD1
#define RD1_SetDigitalInput()   do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()  do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode() do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set Q_SW5V aliases
#define Q_SW5V_TRIS               TRISDbits.TRISD2
#define Q_SW5V_LAT                LATDbits.LATD2
#define Q_SW5V_PORT               PORTDbits.RD2
#define Q_SW5V_ANS                ANSELDbits.ANSD2
#define Q_SW5V_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define Q_SW5V_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define Q_SW5V_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define Q_SW5V_GetValue()           PORTDbits.RD2
#define Q_SW5V_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define Q_SW5V_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define Q_SW5V_SetAnalogMode()  do { ANSELDbits.ANSD2 = 1; } while(0)
#define Q_SW5V_SetDigitalMode() do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set D_PI17 aliases
#define D_PI17_TRIS               TRISDbits.TRISD3
#define D_PI17_LAT                LATDbits.LATD3
#define D_PI17_PORT               PORTDbits.RD3
#define D_PI17_ANS                ANSELDbits.ANSD3
#define D_PI17_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D_PI17_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D_PI17_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D_PI17_GetValue()           PORTDbits.RD3
#define D_PI17_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D_PI17_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define D_PI17_SetAnalogMode()  do { ANSELDbits.ANSD3 = 1; } while(0)
#define D_PI17_SetDigitalMode() do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set channel_PI3V aliases
#define channel_PI3V_TRIS               TRISDbits.TRISD5
#define channel_PI3V_LAT                LATDbits.LATD5
#define channel_PI3V_PORT               PORTDbits.RD5
#define channel_PI3V_ANS                ANSELDbits.ANSD5
#define channel_PI3V_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define channel_PI3V_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define channel_PI3V_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define channel_PI3V_GetValue()           PORTDbits.RD5
#define channel_PI3V_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define channel_PI3V_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define channel_PI3V_SetAnalogMode()  do { ANSELDbits.ANSD5 = 1; } while(0)
#define channel_PI3V_SetDigitalMode() do { ANSELDbits.ANSD5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
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