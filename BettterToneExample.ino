#include <Arduino.h>
#include <BetterTone.h>
#include <Pitches.h>

//Digital and Analog Pins Used on UNO Board
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
	buttonValue = digitalRead(buttonPin); //The integer buttonValue is used to represent buttonPin as an input
	
   if(buttonValue == 1){
		Melody(buzzerPin, NCS1, NB1, NAS5, NG7);
    Serial.print("4 Tones played to pin number "); Serial.print(buzzerPin); Serial.println(""); Serial.println("");

    DoubleTone(buzzerPin, NCS1, NB1);
    Serial.print("2 Tones played to pin number "); Serial.print(buzzerPin); Serial.println(""); Serial.println("");
  
    BetterTone(buzzerPin, NCS1);
    Serial.print(" 1 Tone played to pin number "); Serial.print(buzzerPin); Serial.println(""); Serial.println("");
   }
}
