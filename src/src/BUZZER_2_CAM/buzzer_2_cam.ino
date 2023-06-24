// -- GUIDE POOL DOG
// -- 01 / 06 /2023

// Bibliotheques
#include <Wire.h>
#include <stdio.h>
#include <PixyI2C.h>

#define FREQ 1450
int buzzerPin = 19;
int arrayFREQ[] = {FREQ};

int FREQDurations_ligne[] = {3};
int FREQDurations_bouee[] = {1}; 

int FREQDurations [] = {5,1};

PixyI2C pixy_ligne(0x55); // I2C Adresse
PixyI2C pixy_bouee(0x56); // I2C Adresse 

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  
  pixy_ligne.init();
  pixy_bouee.init();
}

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks_camera_ligne;
  uint16_t blocks_camera_bouee;
  
  blocks_camera_ligne = pixy_ligne.getBlocks(1); 
  blocks_camera_bouee = pixy_bouee.getBlocks(1);

  if (blocks_camera_ligne)
  {
    i++; 
    if (i%20==0) // Toutes les 20 images 
    {
      if(pixy_ligne.blocks[j].x > 45)
      {
          buzzer_ligne();
      }
      
    }
  }

  if (blocks_camera_bouee)
  {
    i++; 
    if (i%10==0) // Toutes les 10 images 
    {
      if(pixy_bouee.blocks[j].x > 0)
      {
          buzzer_bouee();
      }
      
    }
  }
}

void buzzer_ligne(void)
{
    int FREQDuration = 1000/FREQDurations[0];
    tone(buzzerPin, arrayFREQ[0], FREQDuration);

    int pauseBetweenFREQs = FREQDuration +50; 
    delay(pauseBetweenFREQs);

    noTone(buzzerPin);
}

void buzzer_bouee(void)
{
    int FREQDuration = 1000/FREQDurations[1];
    tone(buzzerPin, arrayFREQ[0], FREQDuration);

    int pauseBetweenFREQs = FREQDuration + 50; 
    delay(pauseBetweenFREQs);

    noTone(buzzerPin);
}