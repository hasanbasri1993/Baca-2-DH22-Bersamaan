// DHT code from:
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
// Sumber

#include "DHT.h"
// LCD
// LCD RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
LiquidCrystal lcd( 3, 4, 5, 6, 7, 8);

#define DHTPIN1 13    // what pin we're connected to
#define DHTPIN2 12
#define RelayFan1 11
#define RelayFan2 10
#define RelaySedot 9
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT sensor1(DHTPIN1, DHTTYPE);
DHT sensor2(DHTPIN2, DHTTYPE);

// Global Variables Defined
// This is so we can see them in all functions
// t is the temperature, h is the humidity
// Timer is used to reduce the frequency of reading the DHT11 - I found reading it every loop
// caused timing issues with the Ethernet.
// The Animation loop is to provide some bling to the LCD diaplay

int suhu1 = 0;
int lembab1 = 0;
int suhu2 = 0;
int lembab2 = 0;

void setup () {
   
  pinMode(RelayFan1, OUTPUT);
  pinMode(RelayFan2, OUTPUT);
  pinMode(RelaySedot, OUTPUT);
  digitalWrite(RelayFan1, HIGH);
  digitalWrite(RelayFan2, HIGH);
  digitalWrite(RelaySedot, HIGH);
  
  lcd.begin(16, 2);

  char teks1[] = "Tugas Akhir, Rancangan Miniatur Green House Suhu dan Kelembaban dengan Menggunkan Mikrocontroller";

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
void 
//  Here we get values from the DHT11
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


void loop () {

  StatusSensor1();
  delay(2000);
  StatusSensor2();
  delay(2000);
}
