#include <Arduino.h>
#include <BetterTone.h>
#include <Pitches.h>

//Digital and Analog Pins Used on UNO Board
const int switchPin = 3;    //Digital Pin 2 (No PWM)
const int buzzerPin = 8;    //Digital Pin 8 (No PWM)
const int buttonPin = 9;	//Digital Pin 9 (PWM)

//Default Values for Switch and Button
int buttonValue = 0;

void setup(){
	Serial.begin(115200); //Serial Start
	pinMode(8, OUTPUT); //Buzzer Output Pin
	pinMode(9, INPUT);  //Button Input Pin
}

void loop(){
	buttonValue = digitalRead(buttonPin);
	
     if(buttonValue == 1){
		BetterTone(buttonPin, NC1);
		}
	   }
}
