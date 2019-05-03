#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin1 = 22;
const int buttonPin2 = 24;
const int buttonPin3 = 26;

byte Smile[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte Heart[8] = {
  B00000,
  B00000,
  B11011,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte BrokenHeart[8] = {
  B00000,
  B00000,
  B11011,
  B01111,
  B01010,
  B00100,
  B00000,
};

byte Broken2Heart[8] = {
  B00000,
  B00000,
  B01001,
  B01011,
  B01010,
  B00100,
  B00000,
};
byte DeathHeart[8] = {
  B00000,
  B01110,
  B10101,
  B10101,
  B01110,
  B01010,
  B00000,
};
byte Evil[8] = {
  B00000,
  B10001,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
};

void Smileface() {
  lcd.createChar(0, Smile);
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
}
void HeartF() {
  lcd.createChar(1, Heart);
  lcd.setCursor(1, 0);
  lcd.write(byte(1));
  delay(1000);
}
void BrokenHeartF() {
  lcd.createChar(2, BrokenHeart);
  lcd.setCursor(1, 0);
  lcd.write(byte(2));
  delay(400);
}
void Broken2HeartF() {
  lcd.createChar(3, Broken2Heart);
  lcd.setCursor(1, 0);
  lcd.write(byte(3));
  delay(400);

}
void DeathHeartF() {
  lcd.createChar(4, DeathHeart);
  lcd.setCursor(1, 0);
  lcd.write(byte(4));
  delay(400);

}
void Fullhealth() {
  lcd.createChar(1,Heart);
  lcd.setCursor(13,0);
  lcd.print(char(1));
  lcd.print(char(1));
  lcd.print(char(1));
}
void Evilface() {
  lcd.createChar(0, Evil);
  lcd.setCursor(4, 0);
  lcd.print(char(0));
}

void setup() {
  lcd.begin(16,2);
   pinMode(buttonPin1, INPUT_PULLUP);
   pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(buttonPin3, INPUT_PULLUP);
   lcd.setCursor(2,0);lcd.print("Benvenuto in");lcd.setCursor(1,1);
   lcd.print("Press the Face");delay(3000);lcd.clear();
   
}

void loop() {}
