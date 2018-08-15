/*
  Keyboard

  Plays a pitch that changes based on a changing analog input

  circuit:
  - Potentiometer from +5V to analog in A0
  - 0ne 10 kilohm resistors from analog in A0
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone3
*/

#include "pitches.h"

const int threshold = 300;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A2, NOTE_B4, NOTE_C4
};

void setup() {
  Serial.begin(9600);
}

void loop() {

    int sensorReading = analogRead(A1);
    Serial.println(sensorReading);
    delay(50);
    // if the sensor is pressed hard enough:
    if (sensorReading < 250) {
      // play the note corresponding to this sensor:
      tone(8, notes[0], 20);
    }
    else if (sensorReading > 250 && 500 > sensorReading) {
      // play the note corresponding to this sensor:
      tone(8, notes[1], 20);
    }
    else if (sensorReading > 500) {
      // play the note corresponding to this sensor:
      tone(8, notes[2], 20); 
    }
  }
