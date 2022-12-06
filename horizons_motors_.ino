#include <Servo.h>


const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

Servo myservo;

int distance1,distance2,distance3,distance4;


int ledPin = 6;

void setup() {
  // put your setup code here, to run once:
myservo.attach(2);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {

distance1 = calculatingdistance();
delay(50);
distance2 = calculatingdistance();
delay(50);
distance3 = calculatingdistance();
delay(50);


 Serial.print("Distance1: ");
Serial.println(distance1);

 Serial.print("Distance2: ");
Serial.println(distance2);

 Serial.print("Distance3: ");
Serial.println(distance3);



   if(distance1>=distance2 && distance2>=distance3 && distance1>distance3 ){
    digitalWrite(ledPin, HIGH);
    myservo.write(0);
    Serial.print("oui\n\n");
   }

    else 
    {
      digitalWrite(ledPin, LOW);
      myservo.write(90);
       Serial.print("non\n\n");
    }

}


int calculatingdistance(){
    digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

  return distance;
  
  
}
