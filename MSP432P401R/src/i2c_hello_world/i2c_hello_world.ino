// Guide Pool Dog
// Date : 22 / 05 / 2023

#include <Wire.h>
#include <stdio.h>
#include <PixyI2C.h>

PixyI2C pixy(0x55); // I2C Address

#define LED RED_LED

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");

  pinMode(LED, OUTPUT);
  
  pixy.init();
}


void loop() 
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks(1); // Just take the first block
  
  if (blocks)
  {
    i++;
    
    if (i%50==0) // Every 50 Frames
    {
      if(pixy.blocks[j].x < 130)
      {
          digitalWrite(LED, HIGH);
          delay(1000);
      }
      
    }
    digitalWrite(LED,LOW);
  }  
}
