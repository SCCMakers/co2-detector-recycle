/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int buttonPin = 10;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
//int sensorValue = 0;  // variable to store the value coming from the sensor
//int baseSensorValue=0;
long thirtyMin=30*60;//1000 is one second so 30 minutes should be this
long mills=0;
long start=0;

void setup() {
  //Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin,INPUT);
  playSong();
//  baseSensorValue = analogRead(sensorPin);
  //Serial.println(thirtyMin);
}

void loop() {
  
  if (digitalRead(buttonPin)==HIGH){
    playSong();
    digitalWrite(ledPin,HIGH);
    mills=0;
    while (mills<thirtyMin){
      mills+=1;
      delay(1000);
    }
    while (digitalRead(buttonPin)==LOW){
      playSong();//alarm!!!!
    }
    delay(1000);
  } else {
    digitalWrite(ledPin,LOW);
  }
  delay(100);
 
}

void playSong(){  // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }
}
