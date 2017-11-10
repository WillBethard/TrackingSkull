
#include <Servo.h>

Servo myservo;      // create servo object to control a servo

int serPin = 12;//Pin for use with servo


 boolean fn = false;//Boolean used for reads from first time in loop

 //Pins for photoresistors
int pinIN1 = 1;
int pinIN2 = 2;
int pinIN3 = 3;
int pinIN4 = 8;
int pinIN5 = 5;

//Pins used for LED
int led1 = 7;
int led2 = 6;


//Values for intial reads
int intread1 = 0;
int intread2 = 0;
int intread3 = 0;
int intread4 = 0;
int intread5 = 0;

//Values for averages 
int intavgs1 = 0;
int intavgs2 = 0;
int intavgs3 = 0;
int intavgs4 = 0;
int intavgs5 = 0;


//Values for second reads, used in averages
int intreadtemp1 = 0;
int intreadtemp2 = 0;
int intreadtemp3 = 0;
int intreadtemp4 = 0;
int intreadtemp5 = 0;



void setup()
{
 myservo.attach(12);// attaches servo to digital pin 12

  myservo.write(40);//Sets servo to inital position
    delay(1150);
  pinMode(led1,OUTPUT);//Out[uts for LED pins
  pinMode(led2,OUTPUT);
    

 //Serial.begin(9600); This and other serial code is legacy code that can be used for calibration 
    delay(450);
  
}

void loop() {
  

 
  if(!fn)
  {
  //  Serial.println("Initail reads");
   intread1 = analogRead(pinIN1);
   //Serial.println(intread1);
      delay(500);
   intread2 = analogRead(pinIN2);
   //Serial.println(intread2);
      delay(500);
   intread3 = analogRead(pinIN3);
   //Serial.println(intread3);
      delay(500);
   intread4 = analogRead(pinIN4);
   //Serial.println(intread4);
      delay(500);
   intread5 = analogRead(pinIN5);
   //Serial.println(intread5);
    delay(500);



    
    //Serial.println("Avg reads");
   intreadtemp1 = analogRead(pinIN1);
      delay(500);
   intreadtemp2 = analogRead(pinIN2);
      delay(500);
   intreadtemp3 = analogRead(pinIN3);
      delay(500);
   intreadtemp4 = analogRead(pinIN4);
      delay(500);
   intreadtemp5 = analogRead(pinIN5);
    delay(500);

    
    //Stores averages
     intavgs1 = (intread1+intreadtemp1)/2;
        // Serial.println(intavgs1);
     intavgs2 = (intread2+intreadtemp2)/2;
        //Serial.println(intavgs2);
     intavgs3 = (intread3+intreadtemp3)/2;
        delay(500);
        //Serial.println(intavgs3);
     intavgs4 = (intread4+intreadtemp4)/2;
        //Serial.println(intavgs4);
     intavgs5 = (intread5+intreadtemp5)/2;
        //Serial.println(intavgs5);
   
    fn = true;
  
       delay(500);
  }
  //New reads through photoresistors
  int newreads1 = 0;
  int newreads2 = 0;
  int newreads3 = 0;
  int newreads4 = 0;
  int newreads5 = 0;

  
    //Serial.println("new read values");
  newreads1 = analogRead(pinIN1);
   //Serial.println(newreads1);
  newreads2 = analogRead(pinIN2);
  //Serial.println(newreads2);
  newreads3 = analogRead(pinIN3);
  //Serial.println(newreads3 );
  newreads4 = analogRead(pinIN4);
  //Serial.println(newreads4 );
  newreads5 = analogRead(pinIN5);
  //Serial.println(newreads5);
  boolean loopout = false;
  int index = 0;
 

//compares to see where to move(from right to left )
  if(newreads1+ 30 < intavgs1 )
  {
    //Serial.println("In move 1");
        myservo.write(10);
        digitalWrite(led1,HIGH);//turns LED on
        digitalWrite(led2,HIGH);

  } 
  
  else if(newreads2+ 30 < intavgs2 )
  {
    //Serial.println("In move 2");
        myservo.write(60);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);

  } 
  
    else if(newreads3+ 30 < intavgs3 )
  {
    //Serial.println("In move 3");
        myservo.write(100);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);

  } 
  
    else if(newreads4+ 30 < intavgs4 )
  {
    //Serial.println("In move 4");
        myservo.write(145);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);

  } 
  
    else if(newreads5+ 30 < intavgs5 )
  {
    //Serial.println("In move 5");
        myservo.write(170);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);

  } 
     

  delay(1150);
   digitalWrite(led1,LOW);//Turns led off
    digitalWrite(led2,LOW);
}

