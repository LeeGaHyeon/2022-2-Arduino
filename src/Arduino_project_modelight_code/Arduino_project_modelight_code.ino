// 3색 LED 
// 9 10 11번에 RGB값 
int R = 9;
int G = 10;
int B = 11;

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작 
  pinMode(5, INPUT_PULLUP); // 5번핀에 연결된 조이스틱을 input으로 
  pinMode(9, OUTPUT); // R을 OUTPUT으로
  pinMode(10, OUTPUT); // G를 OUTPUT으로
  pinMode(11, OUTPUT); // B를 OUTPUT으로    
}

void loop() {

  int push = digitalRead(5); // 누르면 0 떼면 1 
  int X = analogRead(A0); // 조이스틱의 X축 좌표를 아날로그값으로 읽음
  int Y = analogRead(A1); // 조이스틱의 Y축 좌표를 아날로그값으로 읽음 
  int count = 0;
  
  Serial.print(" X: "); 
  Serial.print(X);
  
  Serial.print(" Y: "); 
  Serial.print(Y);
      
  Serial.print(" PUSH : ");
  Serial.println(push);

  if (Y>500){
      digitalWrite(R, 255);
      digitalWrite(G, 0);
      digitalWrite(B, 255);
  }else{
      digitalWrite(R, 0);
      digitalWrite(G, 255);
      digitalWrite(B, 255);
      if(X>500){
        digitalWrite(R, 255);
        digitalWrite(G, 255);
        digitalWrite(B, 0);
      }
  }

  if(push == 0){
       digitalWrite(R, 0);
       digitalWrite(G, 0);
       digitalWrite(B, 0);
       count = count+1;
       Serial.print(" button Count: ");
       Serial.print(count);
  }
  delay(1000);
}
