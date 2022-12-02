boolean freqFlag=true;

int flame = 0;
int Beep = 12;
int sw = 10;
int val = 0;
int tempo = 150;

int notes[14] = {C,C,G,G,A,A,G,F,F,E,E,D,D,C};
void setup() {
  pinMode(Beep, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  val = analogRead(flame);
  if(val >= 700)
   {
    for(int freq = 150; freq <=1800; freq = freq + 4) {
    tone(Beep, freq, 10);
  }
  for(int freq = 1800; freq <=150; freq = freq - 2) {
    tone(Beep, freq, 10);
  }
   }else if(digitalRead(sw)==LOW&&val<500){
    for (int i = 0; i < 14; i++) {
    tone (Beep, notes[ i ], tempo);
    delay (300);
      }
   }else{
            noTone(Beep);
       }
  // put your main code here, to run repeatedly:

}
