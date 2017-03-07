#ifndef BETTERTONE_H
#define BETTERTONE_H

#include <Arduino.h>
#include "Pitches.h"

int SingleNoteAmount = 1;
int DoubleNoteAmount = 2;
int MelodyNoteAmount = 4;

int betterNoteDurations[] = {4, 4, 4, 4};

int noteArray[] = {NP0, NA1, NA2, NA3, NA4, NA5, NA5, NA6, NA7,
				   NB0, NB1, NB2, NB3, NB4, NB5, NB6, NB7,
				   NC1, NC2, NC3, NC4, NC5, NC6, NC7, NC8,
				   ND1, ND2, ND3, ND4, ND5, ND6, ND7,
				   NE1, NE2, NE3, NE4, NE5, NE6, NE7,
				   NF1, NF2, NF3, NF4, NF5, NF6, NF7,
				   NG1, NG2, NG3, NG4, NG5, NG6,  NG7,
				   NAS1, NAS2, NAS3, NAS4, NAS5, NAS7,
				   NCS1, NCS2, NCS3, NCS4, NCS5, NCS6, NCS7, NCS8,
				   NDS1, NDS2, NDS3, NDS4, NDS5, NDS6, NDS7,
				   NFS1, NFS2, NFS3, NFS4, NFS5, NFS6, NFS7,
				   NGS1, NGS2, NGS3, NGS4, NGS5, NGS6,  NGS7};

class BetterTone
{
   public:
   BetterTone(int pin, int noteone) : _pin(pin), _noteone(noteone){
	_pin = pin; _noteone = noteone;
	pinMode(pin, OUTPUT);	
	
	for (int noteAmount = 0; noteAmount < 1; noteAmount++){  //Allows for self-correcting note playing
		int betterNoteDuration = 1000 / betterNoteDurations[SingleNoteAmount];   // to calculate the note duration, take one second divided by the note type
		tone(_pin, noteArray[_noteone], betterNoteDuration);
		delay(2000);
		}
	}	
  private:
  int _pin, _noteone;
};

class DoubleTone 
{
	public:
	DoubleTone(int pin, int noteone, int notetwo) : _pin(pin), _noteone(noteone), _notetwo(notetwo){
	_pin = pin;
	pinMode(pin, OUTPUT);
	
	_noteone = noteone; _notetwo = notetwo; 
	
     for (int noteAmount = 0; noteAmount < 1; noteAmount++){  //Allows for self-correcting note playing
		  int betterNoteDuration = 1000 / betterNoteDurations[DoubleNoteAmount];   // to calculate the note duration, take one second divided by the note type
		  tone(_pin, noteArray[_noteone && _notetwo], betterNoteDuration);
		  delay(2000);
		}
	}
  private:
  int _pin, _noteone, _notetwo;
};

class Melody
{
	public:
	Melody(int pin, int noteone, int notetwo, int notethree, int notefour) : _pin(pin), _noteone(noteone), _notetwo(notetwo), _notethree(notethree), _notefour(notefour){
	_pin = pin;
	pinMode(pin, OUTPUT);
	
	_noteone = noteone; _notetwo = notetwo; _notethree = notethree; _notefour = notefour;
	
	 for (int noteAmount = 0; noteAmount < 3; noteAmount++){  //Allows for self-correcting note playing
		  int betterNoteDuration = 1000 / betterNoteDurations[MelodyNoteAmount];   // to calculate the note duration, take one second divided by the note type
		  tone(_pin, noteArray[_noteone && _notetwo && _notethree && _notefour], betterNoteDuration);
		  delay(2000);
		}
	}
  private:
  int _pin, _noteone, _notetwo, _notethree, _notefour;
};
#endif
