/*
 * By Billal Fauzan 
 * Note: silahkan kembangkan sendiri
 *     : ini hanya kode inti nya
 */
 
#include <DHT.h>

#define pin 8 // Gunakan pin out pada dht ke pin 8 pada arduino
#define type DHT11 // Saya menggunakan DHT11

DHT dht(pin, type);

float suhu;
float kelembapan;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  suhu = dht.readTemperature(); // membaca suhu ruangan
  kelembapan = dht.readHumidity(); // membaca kelembapan ruangan

  // menampilkan ke serial monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print("C - Kelembapan");
  Serial.println(kelembapan);

  delay(1000); // delay selama 1000 microsecond atau 1 detik
}
