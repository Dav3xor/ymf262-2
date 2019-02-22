#include <avr/io.h>
#include "../ymf262-common/ymf-common.h"
#include "stdint.h"
#include "defs.h"
#include "I2CSlave.c"

#define I2C_ADDR 0x10

// i2c info:
//
// ads1115 addresses:
// 1001000
// 1001001
// 1001010
// 1001011

// oled addresses:
// who knows...

uint8_t output1[24];
uint8_t output2[24];


void I2C_received(uint8_t received_data)
{
  // we don't care about what we got...
  //data = received_data;
}

void I2C_requested()
{
  for (int i = 0 ; i < 24 ; i++) {
    I2C_transmitByte(output2[i]);
  }
}

int main(void) {

  // set received/requested callbacks
  I2C_setCallbacks(I2C_received, I2C_requested);

  // init I2C
  I2C_init(I2C_ADDR);



  DDRB |= _BV(PB0);
 
  adc_init(); 

  //set_output(PORTB,PB0);

  set_input(PORTC,PC0);
  set_input(PORTC,PC1);

  // set control lines for multiplexer(s)
  DDRD |= _BV(PD0);
  DDRD |= _BV(PD1);
  DDRD |= _BV(PD2);
  DDRD |= _BV(PD3);

  pin_high(PORTD, PD0);
  pin_high(PORTD, PD1);
  pin_high(PORTD, PD2);
  pin_high(PORTD, PD3);

  for(uint8_t i = 0;;i = ((i+1)%16)) {
    if (i&1) {
      pin_high(PORTD, PD0);
    } else {
      pin_low(PORTD, PD0);
    }
    if (i&2) {
      pin_high(PORTD, PD1);
    } else {
      pin_low(PORTD, PD1);
    }
    if (i&4) {
      pin_high(PORTD, PD3);
    } else {
      pin_low(PORTD, PD3);
    }
    if (i&8) {
      pin_high(PORTD, PD4);
    } else {
      pin_low(PORTD, PD4);
    }
    if (routing[i][0]) output1[routing[i][0]] = read_adc(PC0)/routing[i][1];
    if (routing[i][2]) output1[routing[i][2]] = read_adc(PC1)/routing[i][3];
    for (int i = 0; i < 24; i++) {
      output2[i] = output1[1];
    }
        
  }

}

