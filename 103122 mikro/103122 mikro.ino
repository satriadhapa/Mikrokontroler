#include <SoftwareSerial.h>
SoftwareSerial bt (2,3);
#include <Servo.h>

Servo myservo;
int led= 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  myservo.attach(5);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
 char dataBt;

 if(bt.available()>0){
   dataBt= bt.read();
   Serial.println(dataBt);

    if(dataBt == '0'){
      digitalWrite(led, LOW);
      myservo.write(0);            

    } else if (dataBt == '1') {
      digitalWrite(led, HIGH);
        myservo.write(360);             
    }
 }

}
