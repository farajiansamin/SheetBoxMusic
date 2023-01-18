#include "pitches.h"

// Define pins for ultrasonic and buzzer
int const trigPin1 = 10;
int const echoPin1 = 9;
int const trigPin2 = 5;
int const echoPin2 = 6;
int const buzzPin = 2;
int notes [] = {NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};
int duration, duration1, duration2, distance1, distance2;


void setup()
{
  pinMode(trigPin1, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin1, INPUT); // echo pin should be input to get pulse width
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}

void loop()
{
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters

  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin1, LOW);
  delay(100);
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Measure the pulse input in echo pin
  duration1 = pulseIn(echoPin1, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
   digitalWrite(trigPin2, LOW);
  delay(100);
 digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Measure the pulse input in echo pin
  duration2 = pulseIn(echoPin2, HIGH);

  
  distance1 = (duration1*0.0340) / 2;
  distance2 = (duration2*0.0340) / 2;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 

  
    if ((distance1 <= 6 || distance2 <=6) && (distance1 >= 0 || distance2 >= 0)) {
      if(distance1 >= 0 && distance1 <= 6){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
     tone(buzzPin , notes[1] , duration);  
    }
    
     else if  ((distance1 > 6 || distance2 > 6) && (distance1 <= 20 || distance2 <= 20)){
      if(distance1 > 6 && distance1 <= 20){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
      tone(buzzPin , notes[2] , duration);  
     }

      else if  ((distance1 > 20 || distance2 > 20) && (distance1 <= 40 || distance2 <= 40)){
        if(distance1 >= 20 && distance1 < 40){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
  
     tone(buzzPin , notes[3] , duration);  
     }
     
     else if  ((distance1 > 40 || distance2 > 40) && (distance1 <= 60 || distance2 <= 60)){
        if(distance1 >= 40 && distance1 < 60){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
  
     tone(buzzPin , notes[4] , duration);  
     }
     
     else if  ((distance1 > 60 || distance2 > 60) && (distance1 <= 80 || distance2 <= 80)){
        if(distance1 >= 60 && distance1 < 80){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
  
     tone(buzzPin , notes[5] , duration);  
     }
     
     else if  ((distance1 > 80 || distance2 > 80) && (distance1 <= 100 || distance2 <= 100)){
        if(distance1 >= 80 && distance1 < 100){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
  
     tone(buzzPin , notes[6] , duration);  
     }
     
     else if  ((distance1 > 100 || distance2 > 100) && (distance1 <= 120 || distance2 <= 120)){
        if(distance1 >= 100 && distance1 < 120){
        duration = duration1;
      }
      else {
        duration = duration2;
      }
  
     tone(buzzPin , notes[7] , duration);  
     }

      else {
      // Don't buzz
      digitalWrite(buzzPin, LOW);
    }
    // Waiting 60 ms won't hurt any one
    delay(1);
}
