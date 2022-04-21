#define ECHOPIN 7
#define TRIGPIN 8
int led = A5;
#include <LiquidCrystal.h>

LiquidCrystal lcd (6,5,4,3,2,1);
int H2,HT,H1;
void setup() {
  lcd.begin(16,2);
  lcd.print("Tinggi Badan");
  lcd.setCursor(0,1);
  lcd.print("TB=");

  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(led,OUTPUT);
  delay(1000);
  HT = 200;
}
void loop(){
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  int distance = pulseIn(ECHOPIN,HIGH);
  distance = distance/58;
  H2=HT-distance;
  lcd.setCursor(3,1);
  lcd.print(H2);
  lcd.print("cm");
  digitalWrite(led, HIGH);
  delay(1000);
}
