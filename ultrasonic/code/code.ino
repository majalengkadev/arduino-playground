#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int trig = 8; // Gunakan pin trig pada sensor ke pin 8 pada arduino
int echo = 9; // Gunakan pin echo pada sensor ke pin 9 pada arduino
int jarak;
long waktu;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);

  pinMode(trig, OUTPUT); // menjadikan trig sebagai output
  pinMode(echo, INPUT); // menjadikan echo sebagai input
}

void loop() {
  // put your main code here, to run repeatedly:
  bacaJarak(); // berfungsi untuk membaca jarak

  // menampilkan ke serial monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println("CM");

  // menampilkan ke lcd
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(jarak);
  lcd.print("CM");

  delay(600); // delay selama 600 microseconds
}

void bacaJarak() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  waktu = pulseIn(echo, HIGH);

  jarak = waktu * 0.034 / 2;
}

