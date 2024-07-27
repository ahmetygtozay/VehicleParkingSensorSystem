#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Ekranı oluşturun (I2C adresi genellikle 0x27 veya 0x3F olabilir)
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C adresi ve ekran boyutu (16x2) olarak ayarlayın

const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int ledGreenPin = 5;
const int ledRedPin = 6;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);

  lcd.begin(16, 2); // LCD ekranı başlat (16 sütun, 2 satır)
  lcd.backlight(); // Arka ışığı aç
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Ultrasonik sensör ile mesafeyi ölç
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // LCD Ekranda mesafeyi göster
  lcd.clear(); // Ekranı temizle
  lcd.setCursor(0, 0); // İlk satırda başla
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Seri monitörde mesafeyi göster
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED ve Buzzer kontrolü
  if (distance < 80) { // Eğer mesafe 80 cm'den azsa
    digitalWrite(buzzerPin, HIGH); // Buzzer'ı aç
    digitalWrite(ledRedPin, HIGH);  // Kırmızı LED yanar
    digitalWrite(ledGreenPin, LOW); // Yeşil LED söner
  } else {
    digitalWrite(buzzerPin, LOW);   // Buzzer'ı kapat
    digitalWrite(ledRedPin, LOW);   // Kırmızı LED söner
    digitalWrite(ledGreenPin, HIGH); // Yeşil LED yanar
  }

  delay(100); // 100 ms bekle
}
