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
  //read the input from photoPin
  sensorValue = analogRead(photoPin);

  // Adjust the values below to conform to the maximum and minimum
  // numbers you get from the sensor
  int delayT = map(sensorValue, sensorHigh, sensorLow, 5, 50);
  if (delayT < 5)
  {
    delayT = 5;
  }
  else if (delayT > 50)
  {
    delayT = 50;
  }

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  color = random(0, 255);

  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color (random (color), random (color), random (color))); // Each pixel color is randomly determined
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayT); // Delay for a period of time (in milliseconds).
  }
  //The following assigns color values to each spoke in the pattern in turn
  for (int i = 0; i < NUMPIXELS && i <= 4; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 5; i < NUMPIXELS && i <= 9; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 10; i < NUMPIXELS && i <= 14; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 15; i < NUMPIXELS && i <= 19; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 20; i < NUMPIXELS && i <= 24; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 25; i < NUMPIXELS && i <= 29; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 30; i < NUMPIXELS && i <= 34; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 35; i < NUMPIXELS && i <= 39; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 40; i < NUMPIXELS && i <= 44; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 45; i < NUMPIXELS && i <= 49; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 50; i < NUMPIXELS && i <= 54; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
  for (int i = 55; i < NUMPIXELS && i <= 59; i++) {
    pixels.setPixelColor(i, pixels.Color (random (color), 0, 50));
    pixels.show(); 
    delay(delayT); 
  }
}

