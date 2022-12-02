#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float humi, temp;
  temp = dht.readTemperature();
  humi = dht.readHumidity();

  if(isnan(humi) || isnan(temp)){
    Serial.println("Failed to read from DHT sensor!!");
    return;
  }
  
  Serial.print("온도: ");
  Serial.print(temp);
  Serial.println("C");

  Serial.print("습도: ");
  Serial.print(humi);
  Serial.println("%");

  delay(300);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.setCursor(0, 1);
  if(humi < 50){
    lcd.print("good humi");
  }else{
    lcd.print("no laundry");
  }
}
