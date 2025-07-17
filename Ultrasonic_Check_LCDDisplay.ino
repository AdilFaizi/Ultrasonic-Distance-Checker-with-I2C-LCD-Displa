#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

#define TRIG_PIN 3
#define ECHO_PIN 4

long duration;
float distanceCm;
String distanceToString; 

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  delay(100);

  for ( int i = 0; i < 3;i++) {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);

}

void loop() {
  int x = 0;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distanceCm = duration * 0.0343 / 2;
  distanceToString = (String)distanceCm + " cm";
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(distanceToString);
  delay(3000);
  
}
