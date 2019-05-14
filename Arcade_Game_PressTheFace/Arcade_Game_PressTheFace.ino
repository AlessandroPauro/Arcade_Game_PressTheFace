#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Stato;
int x = 1000;
int t;
int v;
int p;
int Score = 0;
bool y = true;
int a = 0;
int b = 0;
int c = 0;
int d = 13;
int NumeroTurni = 0;
int NumeroTurniB = NumeroTurni - 1;
int NumeroErr = 0;
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
  lcd.createChar(6, Smile);
  lcd.setCursor(p, 2);
  lcd.write(byte(6));
  delay(x);
}
void HeartF() {
  lcd.createChar(1, Heart);
  lcd.setCursor(13, 0);
  lcd.write(byte(1));
  delay(x);
}
void HeartF2() {
  lcd.createChar(1, Heart);
  lcd.setCursor(14, 0);
  lcd.write(byte(1));
  delay(x);
}
void HeartF3() {
  lcd.createChar(1, Heart);
  lcd.setCursor(15, 0);
  lcd.write(byte(1));
  delay(x);
}
void GiveHeart() {
  lcd.createChar(1, Heart);
  lcd.setCursor(12, 0);
  lcd.write(byte(1));
  delay(x);
}
void BrokenHeartF() {
  lcd.createChar(2, BrokenHeart);
  lcd.setCursor(1, 0);
  lcd.write(byte(2));
  delay(x);
}
void Broken2HeartF() {
  lcd.createChar(3, Broken2Heart);
  lcd.setCursor(1, 0);
  lcd.write(byte(3));
  delay(x);

}
void DeathHeartF() {
  lcd.createChar(4, DeathHeart);
  lcd.setCursor(1, 0);
  lcd.write(byte(4));
  delay(x);
}


void Evilface() {
  lcd.createChar(5, Evil);
  lcd.setCursor(p, 2);
  lcd.write(byte(5));
  delay(x);
}

void DelateHealth(){
  lcd.setCursor(d,0);
  lcd.write(" ");
  lcd.setCursor(d,0);
  lcd.write(byte(2));
  delay(500);
  lcd.setCursor(d,0);
  lcd.write(" ");
  lcd.setCursor(d,0);
  lcd.write(byte(3));
  delay(500);
  lcd.setCursor(d,0);
  lcd.write(" ");
  lcd.setCursor(d,0);
  lcd.write(byte(4));
  delay(500);
  d = d + 1;
  if (d == 3){Stato = 3;}
  }

void NumeroRandom(){   
 randomSeed(millis());                           
 t = random(3);
   while (NumeroTurniB < NumeroTurni){
    if (t == 0){Smileface();if(digitalRead(buttonPin2) == LOW){Score = Score + 10;NumeroTurniB = NumeroTurniB + 2;}else{Score = Score - 10;DelateHealth();NumeroTurniB = NumeroTurniB + 2;}}else
    if (t == 1){Evilface();if(digitalRead(buttonPin2) == LOW){Score = Score - 10;DelateHealth();NumeroTurniB = NumeroTurniB + 2;}} else 
    if (t == 2){GiveHeart();if(digitalRead(buttonPin2) == LOW){HeartF();NumeroTurniB = NumeroTurniB + 2; }}}
   if(Score<0){Stato = 3;}else {NumeroTurniB = NumeroTurniB + 2;NumeroRandom();} 
}

void RandomButton(){
  randomSeed((millis));
  v = random(3);
  if (v == 0){}
  if (v == 1){}
  if (v == 2){}
}

void BottoniDif() 
{
  lcd.clear();
  lcd.print("Easy Normal Hard");
  while (digitalRead (buttonPin1)!= LOW && digitalRead (buttonPin2)!= LOW && digitalRead (buttonPin3) != LOW) {
    if (digitalRead(buttonPin1) == LOW) {x = x + 300;}else if (digitalRead(buttonPin2) == LOW) {} else if (digitalRead(buttonPin3) == LOW) {x = x - 300;}
  }
}
void Finish(){
   lcd.clear();
   lcd.print("Finish");
   delay(400);
   lcd.setCursor(9,1);
   lcd.print(Score);
   delay(1000);
   lcd.clear();
   if (Score > 10){lcd.print("You Win");}else {lcd.print("You lose");}
  }
void Start()
{
  lcd.clear();
  lcd.setCursor(5, 0); lcd.print("select"); lcd.setCursor(3, 2); lcd.print("difficulty");
  delay(1000);
  BottoniDif();
  lcd.clear();
  lcd.setCursor(4, 0);
  while(y){lcd.print("START");delay(500);lcd.clear();y=false;} 
  Stato = 2;
}

void Gioco() {
  HeartF();
  HeartF2();
  HeartF3();
  NumeroRandom();
  Stato=3;
}
void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  Stato = 1;
  lcd.setCursor(2, 0); lcd.print("Welcome in"); lcd.setCursor(1, 1);
  lcd.print("Press the Face"); delay(3000); lcd.clear();                                                             
}

void loop() {
  if (Stato == 1) {
    Start();
  }
  if (Stato == 2) {
    Gioco();
  }
   if (Stato == 3) {
    Finish();
  }
}
