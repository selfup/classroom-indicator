#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <LiquidCrystal.h>
#include <HttpClient.h>

HttpClient client;
char data[10];
String response;
YunServer server;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {

  digitalWrite(13, LOW);
  delay(3000);
  digitalWrite(13, HIGH);
  delay(1000);

  char teacher[10];
  char cohort[10];

  Bridge.get("teacher", teacher, 10);
  Bridge.get("cohort", cohort, 10);

  delay(500);

  lcd.setCursor(0, 1);
  lcd.print(teacher);
  lcd.print(" - ");
  lcd.print(cohort);

}#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>


YunServer server;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
}

void loop() {

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

}
