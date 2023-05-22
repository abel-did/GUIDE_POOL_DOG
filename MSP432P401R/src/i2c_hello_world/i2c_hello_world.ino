
#include <Wire.h>
#include <stdio.h>
#include <PixyI2C.h>

PixyI2C pixy(0x55); // You can set the I2C address through PixyI2C object 

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  
  pixy.init();
}


void loop() 
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  
  if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
      }
    }
  }  
}
