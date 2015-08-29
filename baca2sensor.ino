// Panggil Liblary Sensor
#include "DHT.h"
// LCD
// Panggil Liblary LCD, RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
LiquidCrystal lcd( 3, 4, 5, 6, 7, 8);

//Macem macem variabel
#define DHTPIN1 13    // what pin we're connected to
#define DHTPIN2 12
#define RelayFan1 11
#define RelayFan2 10
#define RelaySedot 9
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT sensor1(DHTPIN1, DHTTYPE);
DHT sensor2(DHTPIN2, DHTTYPE);


int suhu1 = 0;
int lembab1 = 0;
int suhu2 = 0;
int lembab2 = 0;

void setup () {
  //Setting mode pin Relay jadi output
  pinMode(RelayFan1, OUTPUT);
  pinMode(RelayFan2, OUTPUT);
  pinMode(RelaySedot, OUTPUT);
  //Setting pin Relay jadi LOW / Mati
  digitalWrite(RelayFan1, LOW);
  digitalWrite(RelayFan2, LOW);
  digitalWrite(RelaySedot, LOW);
  //Setting memakai lcd 16 x 2
  lcd.begin(16, 2);

  // Variable starp up
  char teks1[] = "Tugas Akhir, Rancangan Miniatur Green House Suhu dan Kelembaban dengan Menggunkan Mikrocontroller";
  //set lcd cursor pada baris dan kolom
  lcd.setCursor(0, 0);

  lcd.print("Dean");

  lcd.autoscroll();
  lcd.setCursor(16, 1);
  for (int indeks = 0; indeks < 16; indeks++)
  {
    lcd.print(teks1[indeks]);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen for the next loop:
  lcd.clear();

  sensor1.begin();
  sensor2.begin();
}

// Menampilkan pembacaan sensor satu
void StatusSensor1()
{
  suhu1 = sensor1.readHumidity();
  lembab1 = sensor1.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Suhu1: ");
  lcd.print(suhu1);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  lcd.print("Lembab2: ");
  lcd.print(lembab1);
  lcd.print("%");


}
Menampilkan pembacaan sensor dua
void StatusSensor2()
{
  suhu2 = sensor2.readHumidity();
  lembab2 = sensor2.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Suhu2: ");
  lcd.print(suhu2);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  lcd.print("Lembab2: ");
  lcd.print(lembab2);
  lcd.print("%");

}

//mode loop
void loop () {

  StatusSensor1();
  delay(2000);
  StatusSensor2();
  delay(2000);
}
