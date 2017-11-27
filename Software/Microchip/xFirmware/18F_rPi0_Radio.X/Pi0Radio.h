/*
    Raspberry Pi Zero Controller Firmware
          tomcircuit November 16 2017
        
            Application Defines
*/        
 

#ifndef _PI0RADIO_H_
#define _PI0RADIO_H_

#define PI_SHUTDOWN_DURATION (100u)
#define PI_RESTART_DURATION (200u)

/* ADC bounds */
// minimum voltage input is 16V
#define ADC_V24_MIN (158)
// maximum voltage input is 26V
#define ADC_V24_MAX (345)

// minimum voltage input is 16V
#define ADC_V24SW_MIN (158)
// maximum voltage input is 26V
#define ADC_V24SW_MAX (345)

// minimum lamp voltage is 5V
#define ADC_LAMP_MIN (180)
//#define ADC_LAMP_MIN (0)
// maximum lamp voltage is 14V
#define ADC_LAMP_MAX (756)
//#define ADC_LAMP_MAX (8192)

#endif //_PI0RADIO_H_

