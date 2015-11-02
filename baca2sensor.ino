// Panggil Liblary Sensor
#include "DHT.h"
#include <Wire.h>
// Panggil Liblary LCD, RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//Macem macem variabel
#define DHTPIN1 6    // what pin we're connected to
#define DHTPIN2 7
#define RelayFan 8
#define RelayPump 9
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT sensor1(DHTPIN1, DHTTYPE);
DHT sensor2(DHTPIN2, DHTTYPE);

int ratasuhu; //Variabel rata rata suhu
int ratalembab; //Variabel rata rata kelembaban
int suhu1 = 0;
int lembab1 = 0;
int suhu2 = 0;
int lembab2 = 0;

void setup () {
  //Setting mode pin Relay jadi output
  pinMode(RelayFan, OUTPUT);
  pinMode(RelayPump, OUTPUT);
  
  //Setting pin Relay jadi LOW / Mati
  digitalWrite(RelayFan, LOW);
  digitalWrite(RelayPump, LOW);
  //Setting memakai lcd 16 x 2
  lcd.begin(16, 2);


  sensor1.begin();
  sensor2.begin();
}


//mode loop
void loop () {

  suhu1 = sensor1.readHumidity();
  lembab1 = sensor1.readTemperature();
  suhu2 = sensor2.readHumidity();
  lembab2 = sensor2.readTemperature();

  //hitung rata rata suhu dari 2 sensor
  ratasuhu = 2 / (suhu1 + suhu2);
  //hitung rata rata kelembaban dari 2 sensor
  ratalembab = 2 / ( lembab1 + lembab2);

  //logika nya
  if (ratasuhu >= 30 && ratalembab >= 40)
  {
    //Nyalakan relay fan saja
    digitalWrite(RelayFan, HIGH);//turn on the heater

  }

  else if (ratasuhu >= 40 && ratalembab >= 50)

  {

    //Nyalakan kedua relay
    digitalWrite(RelayPump, HIGH);
    digitalWrite(RelayFan, HIGH);

  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Suhu2: ");
    lcd.print(suhu2);
    lcd.print("C ");
    lcd.setCursor(0, 1);
    lcd.print("Lembab2: ");
    lcd.print(lembab2);
    lcd.print("%");
    delay(3000);

    lcd.setCursor(0, 0);
    lcd.print("Suhu1: ");
    lcd.print(suhu1);
    lcd.print("C ");
    lcd.setCursor(0, 1);
    lcd.print("Lembab1: ");
    lcd.print(lembab1);
    lcd.print("%");
    delay(3000);
    lcd.setCursor(0, 0);
    lcd.print("Suhu: ");
    lcd.print(ratasuhu);
    lcd.print("C ");
    lcd.setCursor(0, 1);
    lcd.print("Lembab: ");
    lcd.print(ratalembab);
    lcd.print("%");
    delay(3000);
  }
}

