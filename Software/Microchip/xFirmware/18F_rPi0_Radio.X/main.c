/*
 * Pi0 Radio Control Firmware
 * File:   main.c
 * Author: tomcircuit
 *
 * Created on November 25, 2017
 * 
 */

#define VERSION_MAJ 0
#define VERSION_MIN 1

#define _XTAL_FREQ 16000000
#define USE_AND_MASKS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ws2812.h"
#include "pi0radio.h"
#include "mcc_generated_files/mcc.h"

#define TRUE (1)
#define FALSE (0)

#define STREAM_STATE_INFO (TRUE)

#ifndef SLAVE_WRITE_DATA_TYPE
typedef enum
{
    SLAVE_NORMAL_DATA,
    SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;
#endif

void update_status_reg(void);
void pi_supply_off(void);
void pi_supply_on(void);
void request_pi_run(void);
void request_pi_stop(void);
void myI2CStatusCallback(I2C2_SLAVE_DRIVER_STATUS i2c_bus_state);

void myTimer4ISR(void);

typedef enum {RESET = 0, STANDBY, BOOTING, OPERATE, SHUTDOWN, PI_CONTROL} state_t;

struct pi_power_ctrl_s
{
    state_t state;
    state_t prev;
    uint16_t count;
    uint16_t stopped_count;
    uint8_t running;
    uint8_t power_switch;
} pi_power;

   uint8_t  reg_status = 0;
   uint8_t  reg_control = 0;
   uint32_t led_color = WS2812_OFF;
   uint32_t prev_color = WS2812_OFF+1;
   uint16_t meas_tune = 0;
   uint16_t meas_band = 0;
   uint16_t meas_vol = 0;

void main()
{
   uint16_t meas_pi5v = 0;
   uint16_t meas_pi3v = 0;
   uint16_t pi3v;
   uint16_t pi5v;
   uint8_t  led_counter = 0;

   /* initialize the oscillator, gpio, interrupts, ADC, timers */
   SYSTEM_Initialize();

   /* set initial state of power controller FSM */
   pi_power.state = RESET;

   /* clear the LED counter */
   led_counter = 0;

   /* bigass loop */
   while (1)
   {
      /* ensure CPU clock is 16 MHz */
      OSCILLATOR_Initialize();

      /* restart Timer5 for 100ms interval before overflow */
      TMR5_Initialize();

      /*******************************************************/
      /* EVERYTHING ABOVE TAKES PLACE OUTSIDE OF TIMING LOOP */
      /*******************************************************/

      /* restart Timer0 for AC filament detection */
      TMR0_Initialize();

      /* manage the state counter */
      pi_power.count += 1;
      if (pi_power.count == 0)
         pi_power.count -= 1;

      /* query D17 line to see if Pi is operating */
      pi_power.running = (D_PI17_GetValue() == 0);

      /* manage a count of state iters the Pi is not running */
      if (pi_power.running == FALSE)
      {
         pi_power.stopped_count += 1;
         if (pi_power.stopped_count == 0)
            pi_power.stopped_count -= 1;
      }
      else
         pi_power.stopped_count = 0;

      /**************************************************/
      /* BEGINNING OF POWER CONTROLLER STATE PROCESSING */
      /**************************************************/

      /* STANDBY state hander */

      /* STANDBY state is when the radio has AC power, but the set is switched
       * "off". In STANDBY state the presence of FILAMENT VOLTAGE is checked via
       * RA4/T0CKI. If filament voltage is detected then we proceed to BOOTING
       * state, otherwise, remain in STANDBY state. */

      if (STANDBY == pi_power.state)
      {
         /* upon first entry into STANDBY, clear state and stopped counters */
         if (pi_power.prev != STANDBY)
         {
            pi_power.count = 0;
            pi_power.stopped_count = 0;
            pi_power.prev = STANDBY;
         }

         /* turn off the switched 5V supply to the rPi0W */
         pi_supply_off();

         /* negate the run request signal to the rPi0W */
         request_pi_stop();

         // pixel_color is OFF
         led_color = WS2812_OFF;

         /* check for presence of FILAMENT VOLTAGE. Note that this is specific
          * to a tube retrofit and AC voltage on RA4/T0CKI. If a more
          * conventional switch is used, then RA4 can be checked directly for
          * ON/OFF status. But for detection of AC voltage, however, we use
          * TMR0 to overflow when a few AC cycles are detected. */
         if (pi_power.power_switch)
            pi_power.state = BOOTING;
         else
            pi_power.state = STANDBY;

      } /* if (STANDBY == state) */

      /* BOOTING state hander */

      /* BOOTING state waits for the rPi0 to assert D_PI17 to indicate that it's
       * running, in which case proceed to OPERATE state. If filament is lost,
       * revert to STANDBY state. */

      else if (BOOTING == pi_power.state)
      {
         /* upon first entry into BOOTING, clear state counter */
         if (pi_power.prev != BOOTING)
         {
            pi_power.count = 0;
            pi_power.prev = BOOTING;
         }

         // pixel_color(ORANGE);
         led_color = WS2812_ORANGE;

         /* turn on the switched 5V supply to the rPi0W */
         pi_supply_on();

         /* assert the run request signal to the rPi0W */
         request_pi_run();

         /* check to see if the AC filament voltage is lost, in which case
          * proceed to STANDBY state. */
         if (pi_power.power_switch == FALSE)
            pi_power.state = STANDBY;

         /* check to see if the Pi is running, in which case proceed to
            OPERATE state. */
         if (pi_power.running == TRUE)
             pi_power.state = OPERATE;

      } // if (BOOTING == state)

      /* OPERATE state hander */

      /* OPERATE state is when the rPi0 is powered and doing its thing. If the
       * D17 signal from the rPi0 negates, that indicates a Pi-initiated shut-
       * down sequence and state proceeds to SHUTDOWN. If the AC filament
       * voltage is lost, that indicates a front-panel initiated shutdown
       * sequence and the state proceeds to SHUTDOWN. Otherwise, remain in
       * OPERATE state. */

      else if (OPERATE == pi_power.state)
      {
         /* upon first entry into OPERATE, clear state counter */
         if (pi_power.prev != OPERATE)
         {
            pi_power.count = 0;
            pi_power.prev = OPERATE;
         }

         // pixel_color(WHITE);
         led_color = WS2812_WHITE;

         /* turn on the switched 5V supply to the rPi0W */
         pi_supply_on();

         /* assert the run request signal to the Pi */
         request_pi_run();

         /* check to see if the AC filament voltage is lost, in which case
          * we tell the Pi that it should shut down by negating the run request
          * signal. The power controller proceeds to SUTDOWN state. */
         if (pi_power.power_switch == 0)
         {
            request_pi_stop();
            pi_power.state = SHUTDOWN;
         }

         /* check to see if the Pi has either shutdown or is restarting.
          * in which case we proceed to the PI_CONTROL state, leaving run
          * request signal asserted */
         if (pi_power.running == FALSE)
         {
            pi_power.state = PI_CONTROL;
         }

      } // if (OPERATE == state)

      /* SHUTDOWN state handler */

      /* This handles the case where the AC switch has been turned off, and 
       * the Pi should perform an orderly shutdown. This state gives the Pi
       * time to close the file system and negate D17. After this occurs,
       * this power controller proceeds to STANDBY state.  */

      else if (SHUTDOWN == pi_power.state)
      {
         /* upon first entry into SHUTDOWN, clear state counter */
         if (pi_power.prev != SHUTDOWN)
         {
            pi_power.count = 0;
            pi_power.prev = SHUTDOWN;
         }

         // pixel_color(ORANGE);
         led_color = WS2812_RED;

         /* keep the switched 5V supply to the rPi0W up */
         pi_supply_on();

         /* negate the run request signal to the Pi */
         request_pi_stop();

         /* If Pi has been stopped for PI_SHUTDOWN_DURATION ticks then
          * transition to STANDBY state. */
         if (pi_power.stopped_count > PI_SHUTDOWN_DURATION)
            pi_power.state = STANDBY;

      } // if (SHUTDOWN == state)

      /* PI_CONTROL state handler */

      /* PI_CONTROL handles when the Pi either shuts down or restarts
       * without being instructed to by this power controller. */

      else if (PI_CONTROL == pi_power.state)
      {
         /* upon first entry into PI_CONTROL, clear state counter */
         if (pi_power.prev != PI_CONTROL)
         {
            pi_power.count = 0;
            pi_power.prev = PI_CONTROL;
         }

         // establish pixel_color
         led_color = WS2812_VIOLET;

         /* keep the switched 5V supply to the Pi up */
         pi_supply_on();

         if ((pi_power.count < PI_RESTART_DURATION) && (pi_power.running))
            pi_power.state = OPERATE;

         if ((pi_power.count > PI_RESTART_DURATION) && (pi_power.running == FALSE))
            pi_power.state = STANDBY;

      } // if (PI_CONTROL == state)

      /* RESET state hander */

      /* RESET state is transient, executed once after the MCU is reset.
       * Reset events are POR and BOR. */

      else if (RESET == pi_power.state)
      {
         pi_power.state = STANDBY;
         pi_power.prev = RESET;
         pi_power.count = 0;
         pi_power.stopped_count = 0;

         /* Establish all the GPIO and ADC settings */
         PIN_MANAGER_Initialize();

         led_color = WS2812_BLUE;
         prev_color = WS2812_OFF;

         /* switched 5V supply to the rPi0 is OFF */
         pi_supply_off();

         /* D27 signal to the rPi0 is asserted */
         request_pi_run();

         /* BEEP signal is negated */
         Q_BEEP_SetLow();

         /* status LED is OFF */
         Q_LED_SetLow();

         /* initialize STATUS and CONTROL registers */
         reg_status = 0;
         reg_control = 0;

      } // if (RESET == state)

      /********************************************/
      /* END OF POWER CONTROLLER STATE PROCESSING */
      /********************************************/

      /**************************************/
      /* BEGIN ANALOG CONTROLLER CONVERSION */
      /**************************************/

      /* bring AUX pin high during ADC acqusitions */
      Q_AUX_SetHigh();

      /* initialize ADC */
      ADC_Initialize();

      /* read all three analog control inputs uisng ADC */
      meas_tune = ADC_GetConversion(channel_TUNE);
      meas_band = ADC_GetConversion(channel_BAND);
      meas_vol = ADC_GetConversion(channel_VOL);

      /* measure Pi 3V and 5V rails using ADC */
      meas_pi3v = ADC_GetConversion(channel_PI3V);
      pi3v = ((uint32_t)meas_pi3v * (uint32_t)5000 / (uint32_t)1024);

      meas_pi5v = ADC_GetConversion(channel_PI5V);
      pi5v = ((uint32_t)meas_pi5v * (uint32_t)5000 / (uint32_t)512);

      /* bring AUX pin low after ADC acqusitions */
      Q_AUX_SetLow();

      /***************************************/
      /* END OF ANALOG CONTROLLER CONVERSION */
      /***************************************/

      /* display status information to console */
      if ( STREAM_STATE_INFO )
      {
         printf("\n\n\rLED   0x%08lX",led_color);
         printf("\n\rSTAT  0x%02X",reg_status);
         printf("\n\rCTRL  0x%02X",reg_control);
         printf("\n\rST_CNT  %u",pi_power.count);
         printf("\n\rSP_CNT  %u",pi_power.stopped_count);
         printf("\n\rSTATE   %u",pi_power.state);
         printf("\n\rAC_ON   %u",pi_power.power_switch);
         printf("\n\rPI_RUN  %u",pi_power.running);
         printf("\n\rTUNE    %u",meas_tune);
         printf("\n\rBAND    %u",meas_band);
         printf("\n\rVOLUME  %u",meas_vol);
         printf("\n\n\rPi3V    %u mV",pi3v);
         printf("\n\rPi5V    %u mV",pi5v);
      }

      /* update the NeoPixel LED if necessary
       * warning: this uses MCU PLL, so the timer period will be shorter when
       * color changes! */
      if (prev_color != led_color)
      {

          /* Disable the Global Interrupts */
          INTERRUPT_GlobalInterruptDisable();
          /* Disable the Peripheral Interrupts */
          INTERRUPT_PeripheralInterruptDisable();

          /* increase CPU clock to 64 MHz and drive NEOPIXEL */
          OSCILLATOR_FastClock();
          ws2812_send(led_color);

          /* reduce CPU clock back down to 16 MHz */
          OSCILLATOR_Initialize();

          prev_color = led_color;
      }

      /* Enable the Global Interrupts */
      INTERRUPT_GlobalInterruptEnable();
      /* Enable the Peripheral Interrupts */
      INTERRUPT_PeripheralInterruptEnable();

      /* wait for the interval timer to expire before doing next iteration */
      while (0 == TMR5_HasOverflowOccured());

      /********************************************************/
      /*  EVERYTHING BELOW TAKES PLACE OUTSIDE OF TIMING LOOP */
      /********************************************************/

      /* toggle status LED every five trips through main loop */
      if (led_counter++ >= 4)
      {
         Q_LED_Toggle();
         led_counter = 0;
      }

      /* Check for filament activity on T0CKI on the outside of timing loop
         to allow sufficient time for 60 Hz AC cycles to accumulate.  */
      pi_power.power_switch = TMR0_HasOverflowOccured();

      /* update the status register in case there's an I2C read */
      update_status_reg();

   } // while(1)
}

void update_status_reg(void)
{
/* create STATUS register to be ready for I2C read
 * [0] = STATUS {r}
 * [AC][PI 5V][PI RUN][RUN REQ][0][STATE]
 *  |     |      |        |          |
 *  |     |      |        |          +------ 3 bits for STATE info:
 *  |     |      |        |                000 = RESET, 001 = STANDBY,
 *  |     |      |        |                010 = BOOTING,011 = OPERATE,
 *  |     |      |        |                100 = SHUTTING DOWN,
 *  |     |      |        |                101 = Pi INITIATED RESTART/SHUTDOWN
 *  |     |      |        +------------------ 1 == Pi D27 asserted (LOW)
 *  |     |      +--------------------------- 1 == Pi D17 asserted (LOW)
 *  |     +---------------------------------- Pi is supplied with 5V
 *  +---------------------------------------- AC is detected
 */
     reg_status = ((pi_power.power_switch & 1) << 7) |
             ((Q_SW5V_GetValue() & 1) << 6) |
             ((pi_power.running & 1) << 5 ) |
             ((Q_PI27_GetValue() & 1) << 4) |
             (pi_power.state & 7);
}

void pi_supply_off(void)
{
   /* turn off the Pi switched 5V supply */
   Q_SW5V_SetLow();
}

void pi_supply_on(void)
{
   /* turn on the Pi switched 5V supply */
   Q_SW5V_SetHigh();
}

void request_pi_run(void)
{
   /* assert run reqest (D27) signal to Pi */
   Q_PI27_SetHigh();
}

void request_pi_stop(void)
{
   /* negate run request (D27) signal to Pi */
   Q_PI27_SetLow();
}

/*******************************************************/
/*  Pi Radio implementation of I2C callback function   */
/*******************************************************/

/*  This I2C slave includes the following I2C functionality:
 *
 * FOUR read-only registers at sub-addresses 0...3
 *
 * [0] = STATUS {r}
 * [AC][PI 5V][PI RUN][RUN REQ][0][STATE]
 *  |     |      |        |          |
 *  |     |      |        |          +------ 3 bits for STATE info:
 *  |     |      |        |                000 = RESET, 001 = STANDBY,
 *  |     |      |        |                010 = BOOTING,011 = OPERATE,
 *  |     |      |        |                100 = SHUTTING DOWN,
 *  |     |      |        |                101 = Pi INITIATED RESTART/SHUTDOWN
 *  |     |      |        +------------------ 1 == Pi D27 asserted (LOW)
 *  |     |      +--------------------------- 1 == Pi D17 asserted (LOW)
 *  |     +---------------------------------- Pi is supplied with 5V
 *  +---------------------------------------- AC is detected
 *
 * [1] = TUNE VALUE {r}
 *  8 BIT TUNE VALUE
 *
 * [2] = BAND VALUE {r}
 *  8 BIT BAND VALUE
 *
 * [3] = VOL VALUE {r}
 *  8 BIT VOLUME VALUE
 *
 * Random access reads can be performed by writing a single byte
 * REGISTER address, followed by 1 or more reads (auto-increment)
 * 
 * Random access writes can be performed by writing a single byte
 * REGISTER address, followed by 1 or more writes (auto-increment)
 * 
 * Every read or write will increment the internal REGISTER address.
 * 
 * When the end of the REGISTERS are reached, the EEPROM address will
 * continue from the start of the EEPROM.
*/

/**************************************************************/
/* custom I2C callback to implement the communication with Pi */
/**************************************************************/

void I2C2_StatusCallback(I2C2_SLAVE_DRIVER_STATUS i2c_bus_state)
{
    static uint8_t RegAddress = 0;
    static uint8_t slaveWriteType = SLAVE_NORMAL_DATA;

    switch (i2c_bus_state)
    {
        case I2C2_SLAVE_WRITE_REQUEST:
            // the master will be sending the register address next
            slaveWriteType = SLAVE_DATA_ADDRESS;
            break;


        case I2C2_SLAVE_WRITE_COMPLETED:
            switch(slaveWriteType)
            {
                case SLAVE_DATA_ADDRESS:
                    RegAddress = I2C2_slaveWriteData;
                    break;

                case SLAVE_NORMAL_DATA:
                default:
                    // the master has written data to store in a register
                    /* autoincrement register address */
                    RegAddress += 1;
                    RegAddress &= 3;
                    break;
            } // end switch(slaveWriteType)

            slaveWriteType  = SLAVE_NORMAL_DATA;
            break;

        case I2C2_SLAVE_READ_REQUEST:
            // the master needs to read a register value
            /* STATUS register */
            if (RegAddress == 0)
            {
               SSP2BUF = reg_status;
            }
            /* TUNE register */
            if (RegAddress == 1)
            {
               SSP2BUF = meas_tune;
            }
            /* BAND register */
            else if (RegAddress == 2)
            {
               SSP2BUF = meas_band;
            }
            /* VOL register */
            else if (RegAddress == 3)
            {
               SSP2BUF = meas_vol;
            }
            /* autoincrement register address */
            RegAddress += 1;
            RegAddress &= 3;
            break;

        case I2C2_SLAVE_READ_COMPLETED:
        default:;

    } // end switch(i2c_bus_state)

}
