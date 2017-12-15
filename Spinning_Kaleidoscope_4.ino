/*Kaleidoscope with Motion-Controlled Spin
   by Rosco Bell, Dec. 2017
   Based on Caleisdoscopio by José Daniel Herrera Gomariz
   http://arduino-guay.blogspot.com.es/2014/06/caleidoscopio-con-arduino-y-tiras-de.html
     and
   An Optical Theremin by Massimo Banzi
   https://www.youtube.com/watch?v=57S3dylfw3I
     and
   NeoPixel Ring simple sketch (c) 2013 Shae Erisson
   released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Pin on the Arduino connected to the NeoPixels
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            7

// # of NeoPixels attached to the Arduino
#define NUMPIXELS      60

const int ledPin = 13;    //LED pin
const int photoPin = A0;  //Photoresistor pin
int sensorValue = 0;
int sensorLow = 1023;
int sensorHigh = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
byte color = 0;
int c = 0;

//Fill kaleidoscope with spokes of random color
void fill() {
  for (int i = 0; i < NUMPIXELS && i <= 4; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 5; i < NUMPIXELS && i <= 9; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 10; i < NUMPIXELS && i <= 14; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 15; i < NUMPIXELS && i <= 19; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 20; i < NUMPIXELS && i <= 24; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 25; i < NUMPIXELS && i <= 29; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 30; i < NUMPIXELS && i <= 34; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 35; i < NUMPIXELS && i <= 39; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 40; i < NUMPIXELS && i <= 44; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 45; i < NUMPIXELS && i <= 49; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 50; i < NUMPIXELS && i <= 54; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
  for (int i = 55; i < NUMPIXELS && i <= 59; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color)));
    pixels.show();
    delay(15);
  }
}



void setup() {
  //turn on LED to signal start of the calibration
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(photoPin);

    //record the maximum sensor value
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }

    //record the minumum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // signal the end of the calibration period
  digitalWrite(ledPin, LOW);

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  color = random(0, 255);
  //start with random rotation
  fill();

  //Set up rotating patterns
  int spokes[][12] = {{0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19},
    {20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34},
    {35, 36, 37, 38, 39},
    {40, 41, 42, 43, 44},
    {45, 46, 47, 48, 49},
    {50, 51, 52, 53, 54},
    {55, 56, 57, 58, 59}
  };
  int pattern[][12] = {
    {0, random(0, 255), random(0, 255), random(0, 255), random(0, 255)}, {random(0, 255), 0, random(0, 255), random(0, 255), random(0, 255)}, {random(0, 255), random(0, 255), 0, random(0, 255), random(0, 255)}, {random(0, 255), random(0, 255), random(0, 255), 0, random(0, 255)}, {random(0, 255), random(0, 255), random(0, 255), random(0, 255), 0}, {random(0, 255), random(0, 255), random(0, 255), random(0, 255), random(0, 255)}
    , {0, random(0, 255), random(0, 255), random(0, 255), random(0, 255)}, {random(0, 255), 0, random(0, 255), random(0, 255), random(0, 255)}, {random(0, 255), random(0, 255), 0, random(0, 255), random(0, 255)}, {random(0, 255), random(0, 255), random(0, 255), 0, random(0, 255)}, {random(0, 255), random(0, 255), random(0, 255), random(0, 255), 0}, {random(0, 255), random(0, 255), random(0, 255), random(0, 255), random(0, 255)}
  };

  int n = 0;
  int q = 0;
  int m = 0;
  int j = 0;

  for (int n = 0; n <= 1; n++) {

    for (c = 0; c <= 1; c++) {
      fill();
    }
    for (int q = 0; q <= 11; q++) {
      for (int m = 0; m < 12; m++) {
        for (int j = 0; j <= 4; j++) {
          //read the input from photoPin
          sensorValue = analogRead(photoPin);
          // Adjust the values below to conform to the maximum and minimum
          // numbers you get from the sensor
          int delayTime = map(sensorValue, sensorHigh, sensorLow, 0, 50);
          if (delayTime <= 0)
          {
            delayTime = 0;
          }
          else if (delayTime >= 50)
          {
            delayTime = 50;
          }
          delay(delayTime);
          pixels.setPixelColor(spokes[m][j], pattern[q][j, pixels.Color(q, j, n)]);
          pixels.show();
        }
      }
    }
  }
}




