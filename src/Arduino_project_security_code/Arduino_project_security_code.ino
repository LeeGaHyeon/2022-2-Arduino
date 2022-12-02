#include <Stepper.h>
#define STEPS 2048 //한바퀴를 이루는 스텝의 수

Stepper mystepper(STEPS, 11, 9, 10, 8);

void setup() {
  pinMode (13, OUTPUT); //LED
  pinMode (7, INPUT); //인체감지센서

  pinMode(2, OUTPUT); // 초음파 trig
  pinMode(3, INPUT); // 초음파 echo

  mystepper.setSpeed(15); //회전속도 설정
                          //아두이노 10-15(5V 한계)
}

void loop() {
  if (digitalRead(4) == HIGH) {// 인체감지센서 활성화
    for (int j = 0; j < 3; j++) { //활성화과 됐음을 알리기 위함 경고음 3번
      tone(5, 262, 250);
      delay(500);
    }
    for (int k = 0; k < 10000000; k++) {// 대략 24시간동안 동작됨을 표현함(K < 1000000)
      int value = 0;
      value = digitalRead(7); 
      if (value == HIGH) { // 인체 센서에 감지되면 경고음과 LED 깜박임
        for (int i = 0; i < 10; i++) { //(10번 깜박이면 끝
          digitalWrite(13, HIGH);
          tone(5, 262, 250);
          delay(500);
          digitalWrite(13, LOW);
          tone(5, 262, 250);
          delay(500);
        }
      }
      else {
        digitalWrite(13, LOW);
      }

    }
    tone(5, 262, 250);
  }
  
  if (digitalRead(12) == HIGH) { // 초음파 선풍기를 활성화하는 버튼
    tone(5, 262, 250);
    delay(500);

    long duration;
    digitalWrite(2, HIGH);
    delayMicroseconds(10);
    digitalWrite(2, LOW);

    duration = pulseIn(3, HIGH);
    long value = duration / 29 / 0.2;

    if(value < 30){  30 이내로 초음파 감지되면 스텝모터 돌아감(선풍기 작동)

      mystepper.step(STEPS*2); //정방향, 2048 정회전 한바퀴

    }


  }
}
