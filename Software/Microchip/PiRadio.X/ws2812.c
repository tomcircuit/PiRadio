#include <xc.h>
#include "ws2812.h"

#define _XTAL_FREQ 64000000
 
// transmit the ws2812 led
void ws2812_send(unsigned long led)
{
   unsigned char j;

   // color info is stored in a long:
   // msb                               lsb
   // [00000000][B0...B7][R0...R7][G0...G7]

   // the WS2812 wants bits in the order of:
   // G[7..0] R[7..0] B[7..0]
   // i.e. G7 is the first bit shifted out
 
   // begin shifting them over one at a time
   for(j = 0; j < 24; j++) {
      // depending on if the currently viewed bit is 1 or 0
      // the pin will stay high for different times
       
      if (led & 1) {
         // if it is a 1, let it stay higher a bit longer
         #asm
            bsf PORTC,1
            nop
            nop
            nop
            bcf PORTC,1
         #endasm
      } else {
         // but a 0 should go high and then low as fast as possible
         #asm
            bsf PORTC,1
            bcf PORTC,1
            nop
            nop
            nop
         #endasm
      }

      // and then right shift to get the next bit
      led = led >> 1L;
   }
   // delay 50us to ensure the word gets accepted into WS2812
   __delay_us(50);
   #asm
     bsf PORTC,1
     bcf PORTC,1
   #endasm
}
 
