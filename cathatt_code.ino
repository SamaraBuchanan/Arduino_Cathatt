#include <CapacitiveSensor.h>

byte SEND       = 12;   // capacitance
byte RECIEVE    = 10;   // capacitance 
int  vibratePin = 6;    // digital pin 6
int  leftEye    = 2;    // digital pin 2
int  rightEye   = 3;    // digital pin 3

CapacitiveSensor sense = CapacitiveSensor(SEND, RECIEVE);     // Inititalize capacitive sensor


// SETUP ============================================ SETUP
void setup()
{
  sense.set_CS_AutocaL_Millis(0xFFFFFFFF);  // Turn off auto calibration 

  pinMode(vibratePin, OUTPUT);
  pinMode(leftEye, OUTPUT);
  pinMode(rightEye, OUTPUT);
  
  Serial.begin(9600);
  }

// LOOP =============================================== LOOP
void loop()
{
  long val  = sense.capacitiveSensor(2);  // samples 2 capacitive sensing materials

  //Serial.print("\n\nval:");  // for testing
  //Serial.print(val);

  digitalWrite(4, HIGH); // make sure no noise on digital pin 
  
  // Determining if the conductive wire has been touched
  if(val > 10) 
  {
    Serial.print("\nMEOW!\n"); 
    digitalWrite(vibratePin, HIGH); // vibrate
    digitalWrite(leftEye, HIGH);    // turn left LED on
    digitalWrite(rightEye, HIGH);   // turn right LED on
    delay(500);  // delay half a second
  }
  // Otherwise, turn the lights off, stop "purring"
  else
  {
    digitalWrite(vibratePin, LOW);  //stop vibrating
    digitalWrite(leftEye, LOW);
    digitalWrite(rightEye, LOW);
    delay(500); // delay half a second   
  }

  delay(15); // allow small delay so that capacitive sensor library functions properly
  
}