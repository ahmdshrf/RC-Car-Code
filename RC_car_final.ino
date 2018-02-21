#include "NewPing.h"
void check();
//motor a 
int enA = 9;
int in1 = 8;
int in2 = 7;

//motor b
int in3 = 5;
int in4 = 4;
int enB = 3;
char data[32]; // Allocate some space for the string

#define trigPin 10
#define echoPin 13
#define max_distance 400
NewPing sonar(trigPin,echoPin,max_distance);
int duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.println("\n String conversion testing");
}



void loop() {
distance = sonar.ping_cm();
Serial.print("Distance = ");
if(distance >= 400 || distance <=2)
{
  Serial.println("out of range");
}
else
{
  Serial.print ('#');
  Serial.print(distance);
  Serial.print ('~');
  delay (10);
  Serial.println("cm");
  
 }

for(int i=1; i<=3; i++) {
        String servo = Serial.readStringUntil(':');
        if(servo != ""){
        
            int direc = servo.toInt();
            Serial.println(direc);
            String pos = Serial.readStringUntil('.');
            int speeds = pos.toInt();
            Serial.println(speeds);
        
    void check();
     int s;
     s = map(speeds, 0, 100, 0, 255);     
    if (direc >= 85 &&direc <=100 ){//odam
        
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,s);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,s);
        
    }

      else if (direc >=260 && direc <=280){                          //reverse
        
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,s);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,s);   
      }

     else if (direc >=350 && direc <=360 | direc <=10 && direc >=0){ // RIGHT
        
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,s);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,s);
     }

      else if (direc >=170 && direc <=190){                            // LEFT
        
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,s);
        digitalWrite(in3,HIGH);   
        digitalWrite(in4,LOW);
        analogWrite(enB,s);
      }
                
      else if (direc >=120 && direc <=150){                   //FORWARD LEFT
        
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,s);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,s);
      }

      else if (direc >=30 && direc <=60){                       // FORWARD RIGHT
        
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,s);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,s);
      }
        
     else if (direc >=210 && direc <=259){                      // BACKWARD LEFT
        
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,s);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,s);
     }

     else if (direc >=300 && direc <=340){                     // BACKWARD RIGHT
       
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,s);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,s);
     }


      else{                                                   //If bluetooth module receives any value not listed above, both motors turn off
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
      }
   
  }
}
}

void Check()
{
  if(distance <= 10)
  {
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
        delay (1000);
  }
}
 
