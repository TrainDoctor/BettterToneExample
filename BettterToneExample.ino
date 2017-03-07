#include <Arduino.h>
#include "BetterTone.h"
#include "Pitches.h"

//Pins Used on UNO Board
const int buzzerPin = 8;    //Pin 8 
const int buttonPin = 9;	//Pin 9

//Default Values for Switch and Button
int buttonValue = 0;

void setup(){
	Serial.begin(115200); //Serial Start
	pinMode(8, OUTPUT); //Buzzer Output Pin
	pinMode(9, INPUT);  //Button Input Pin
}

void loop(){
	buttonValue = digitalRead(buttonPin); //The integer buttonValue is used to represent buttonPin as an input
	
   if(buttonValue == 1){
    BetterTone(buzzerPin, NCS1);
    Serial.print(" 1 Tone played to pin number "); Serial.print(buzzerPin); Serial.println(""); Serial.println("");
   }
}
