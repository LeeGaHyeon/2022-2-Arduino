#include <Servo.h>
Servo myServo;

int SERVO_pin = 3;
int COS_pin = A0;

boolean blind_state = false;

void setup() {
  myServo.attach(SERVO_pin);
  pinMode(COS_pin, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
   int cds_value = analogRead(COS_pin);
   Serial.println(String("cds:")+cds_value);
   if(cds_value < 400){
    if(blind_state == false){
      myServo.write(0);
      delay(500);
      myServo.write(180);
      blind_state = true;
    }
   }else{
      if(blind_state == true){
      myServo.write(180);
      delay(500);
      myServo.write(0);
      blind_state = false;
      }
   }
  // put your main code here, to run repeatedly:

}
