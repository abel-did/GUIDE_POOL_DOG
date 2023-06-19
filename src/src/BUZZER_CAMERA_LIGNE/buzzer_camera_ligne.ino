// Guide Pool Dog
// Date : 22 / 05 / 2023

#include <Wire.h>
#include <stdio.h>
#include <PixyI2C.h>

#define FREQ 1450
int buzzerPin = 19;
int arrayFREQ[] = {FREQ};
int FREQDurations[] = {2};

PixyI2C pixy(0x55); // I2C Address

#define LED RED_LED

void setup()
{
  pinMode(LED, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
  
  pixy.init();
}


void loop() 
{ 
  static int i = 0;
  int j;
  uint16_t blocks_camera_ligne;
  char buf[32]; 
  
  blocks_camera_ligne = pixy.getBlocks(1); // Just take the first block
  
  if (blocks_camera_ligne)
  {
    i++;
    
    if (i%50==0) // Every 50 Frames
    {
      if(pixy.blocks[j].x > 45)
      {
          buzzer();
      }
      
    }
  }  
}

void buzzer(void)
{
    int FREQDuration = 1000/FREQDurations[0];
    tone(buzzerPin, arrayFREQ[0], FREQDuration);

    int pauseBetweenFREQs = FREQDuration + 50; 
    delay(pauseBetweenFREQs);

    noTone(buzzerPin);
}
