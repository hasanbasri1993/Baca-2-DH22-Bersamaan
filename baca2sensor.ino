// Panggil Library Sensor
// Download Library
#include "DHT.h"
#include <Wire.h>
// Panggil Library LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Macam macam variabel
#define SOILPIN A0      // sensor tanah
#define DHTPIN1 6       // sensor suhu dan lembab 1
#define DHTPIN2 7       // sensor suhu dan lembab 2
#define RelayFan 8      // pin kipas
#define RelayPump 9     // pin pompa air dan buuzer
#define DHTTYPE DHT22   // DHT 22 (AM2302)

// the sensor value description
// 0  ~300     dry soil
// 300~700     humid soil
// 700~950     in water

DHT sensor1(DHTPIN1, DHTTYPE);
DHT sensor2(DHTPIN2, DHTTYPE);

int ratasuhu; //Variabel rata Suhu Ruangan
int ratalembab; //Variabel rata rata kelembaban
int ratatanah;
int baliklembab;
int suhu1 = 0;
int lembab1 = 0;
int suhu2 = 0;
int lembab2 = 0;
int lembabtanah = 0;

void setup() {
  // Setting mode pin Relay jadi output
  pinMode(RelayFan, OUTPUT);
  pinMode(RelayPump, OUTPUT);
  Serial.begin(9600);
  // Setting pin Relay jadi LOW / Mati
  digitalWrite(RelayFan, LOW);
  digitalWrite(RelayPump, LOW);
  //Setting memakai LCD 20 x 4
  lcd.begin(20, 4);


  sensor1.begin();
  sensor2.begin();

}

//mode loop
void loop() {

  suhu1 = sensor1.readTemperature();
  lembab1 = sensor1.readHumidity();
  suhu2 = sensor2.readTemperature();
  lembab2 = sensor2.readHumidity();
  lembabtanah = analogRead(A1);
  if (lembabtanah >= 512)
  {
    baliklembab = 1024 - lembabtanah
  }
  else
  {
    baliklembab = 1024 + lembabtanah
  }
  //hitung rata Suhu Ruangan dari 2 sensor
  ratasuhu = (suhu1 + suhu2) / 2 ;
  //hitung rata rata kelembaban dari 2 sensor
  ratalembab = (lembab1 + lembab2) / 2 ;
  //persentase kelembaban tanah
  ratatanah = (lembabtanah / 1024.0) * 100 ;

  //logika nya
  if (ratasuhu >= 30 && ratalembab >= 50) //|| (ratasuhu <= 39 && ratalembab >= 59)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miniatur Green House");
    lcd.setCursor(0, 1);
    lcd.print("Suhu Ruangan: ");
    lcd.print(ratasuhu);
    lcd.print("C");
    lcd.setCursor(0, 2);
    lcd.print("Lembab Udara: ");
    lcd.print(ratalembab);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Lembab Tanah: ");
    lcd.print(ratatanah);
    lcd.print("%");
    Serial.print(ratatanah);
    Serial.print("     ");
    Serial.println(lembabtanah);
    digitalWrite(RelayFan, HIGH);//turn on the heater
    digitalWrite(RelayPump, LOW);
  }

  else if (ratatanah <= 50)

  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miniatur Green House");
    lcd.setCursor(0, 1);
    lcd.print("Suhu Ruangan: ");
    lcd.print(ratasuhu);
    lcd.print("C");
    lcd.setCursor(0, 2);
    lcd.print("Lembab Udara: ");
    lcd.print(ratalembab);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Lembab Tanah: ");
    lcd.print(ratatanah);
    lcd.print("%");
    Serial.print(ratatanah);
    Serial.print("     ");
    Serial.println(lembabtanah);
    digitalWrite(RelayFan, LOW);
    digitalWrite(RelayPump, HIGH);

  }
  else
  {

    digitalWrite(RelayFan, LOW);
    digitalWrite(RelayPump, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miniatur Green House");
    lcd.setCursor(0, 1);
    lcd.print("Suhu Ruangan: ");
    lcd.print(ratasuhu);
    lcd.print("C");
    lcd.setCursor(0, 2);
    lcd.print("Lembab Udara: ");
    lcd.print(ratalembab);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Lembab Tanah: ");
    lcd.print(ratatanah);
    lcd.print("%");
    Serial.print(ratatanah);
    Serial.print("     ");
    Serial.println(lembabtanah);




  }

  delay(2000);

}
