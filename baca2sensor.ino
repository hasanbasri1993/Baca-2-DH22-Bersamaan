// Panggil Liblary Sensor
#include "DHT.h"
// Panggil Liblary LCD, RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Macem macem variabel
#define DHTPIN1 6    // what pin we're connected to
#define DHTPIN2 7
#define RelayFan1 8
#define RelayFan2 9
#define RelayPump 10
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
  pinMode(RelayPump, OUTPUT);
  //Setting pin Relay jadi LOW / Mati
  digitalWrite(RelayFan1, LOW);
  digitalWrite(RelayFan2, LOW);
  digitalWrite(RelayPump, LOW);
  //Setting memakai lcd 16 x 2
  lcd.begin(16, 2);

  // Variable starp up
  char teks1[] = "Tugas Akhir, Rancangan Miniatur Green House Suhu dan Kelembaban dengan Menggunkan Mikrocontroller";
  //set lcd cursor pada baris dan kolom
  lcd.setCursor(0, 0);

  lcd.print("Dean Yongkky");

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


//mode loop
void loop () {

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
 // jika suhu #mis 30 
 if(suhu1 < 30)//Sesuaikan dengan suhu yang diinginkan
  {
    //maka relay akan menyala 
    digitalWrite(RelayPump, HIGH);//turn on the heater

  }

  else

  {

    digitalWrite(RelayPump, LOW);

  }


}

