/* Originally posted on www.bbangpan.com

   Program Description: 433/315Mhz transmitter(FS1000A or XY-FS) test code
   Needed library : VirtualWire  http://www.airspayce.com/mikem/arduino/VirtualWire/index.html
   DataPin : 12 to 433/315Mhz transmitter DATA(near GND)
   Tested on : Arduino 1.0.6, Arduino UNO R3, VirtualWire

   Inspired by http://www.buildcircuit.com/how-to-use-rf-module-with-arduino/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <VirtualWire.h>

const int TX_DIO_Pin = 12; // default 12


void setup()
{
  vw_set_tx_pin(TX_DIO_Pin); // Initialize TX pin
  vw_setup(2000); // Transfer speed : 2000 bits per sec
}

void loop()
{
  send("Bbangpan!");
  delay(1000);
}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

