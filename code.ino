/*
* Author: Kamran A.
* Description: NTP TIME WITH LEDs
*/

#include <M5Core2.h>
#include <WiFi.h>
#include "time.h"

#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 25
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

// Set the name and password of the wifi to be connected
const char* ssid = "ssid";
const char* password = "password";

const char* ntpServer = "time1.google.com";  //Set the connect NTP server
//const char* ntpServer = "pool.ntp.org";
//const long gmtOffset_sec = -19001;
const long gmtOffset_sec = -18000;
const int daylightOffset_sec = 3600;

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(
          &timeinfo)) {
    M5.Lcd.println("Failed to obtain time");
    return;
  }
  M5.Lcd.println(
      &timeinfo,
      "%a %B %d %Y \n\n     %I:%M:%S");
}

void setup() {
  M5.begin();

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // GRB ordering is assumed
  FastLED.setBrightness(10);
  
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("\nConnecting to %s", ssid);
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Orange;
  leds[4] = CRGB::Cyan;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Green;
  leds[8] = CRGB::Orange;
  leds[9] = CRGB::Cyan;
  FastLED.show();
  WiFi.begin(
      ssid,
      password);
  while (WiFi.status() !=
         WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }
  M5.Lcd.println("\nWIFI CONNECTED!");
  leds[0] = CRGB::Green;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Green;
  leds[5] = CRGB::Green;
  leds[6] = CRGB::Green;
  leds[7] = CRGB::Green;
  leds[8] = CRGB::Green;
  leds[9] = CRGB::Green;
  FastLED.show();
  delay(500);
  M5.Lcd.println("\nCONNECTING TO NTP SERVER");
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Orange;
  leds[4] = CRGB::Cyan;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Green;
  leds[8] = CRGB::Orange;
  leds[9] = CRGB::Cyan;
  FastLED.show();
  delay(500);
  configTime(gmtOffset_sec, daylightOffset_sec,
             ntpServer);
  leds[0] = CRGB::Green;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Green;
  leds[5] = CRGB::Green;
  leds[6] = CRGB::Green;
  leds[7] = CRGB::Green;
  leds[8] = CRGB::Green;
  leds[9] = CRGB::Green;
  FastLED.show();
  delay(500);
  printLocalTime();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  delay(20);
  M5.Lcd.clear();
}
void loop() {

  M5.update();
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 80);
  M5.Lcd.setTextSize(3);

  while(true)
  {
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    M5.Lcd.setTextSize(3);
    Orange();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Red();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Green();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Blue();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Yellow();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Purple();
    printLocalTime();
    M5.update();
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 80);
    Cyan();
    printLocalTime();
  }
}
void Orange()
{
  M5.Lcd.setTextColor(TFT_ORANGE);
  leds[0] = CRGB::Orange;
  leds[1] = CRGB::Orange;
  leds[2] = CRGB::Orange;
  leds[3] = CRGB::Orange;
  leds[4] = CRGB::Orange;
  leds[5] = CRGB::Orange;
  leds[6] = CRGB::Orange;
  leds[7] = CRGB::Orange;
  leds[8] = CRGB::Orange;
  leds[9] = CRGB::Orange;
  FastLED.show();
}
void Red()
{
  M5.Lcd.setTextColor(TFT_RED);
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
  FastLED.show();
}
void Green()
{
  M5.Lcd.setTextColor(TFT_GREEN);
  leds[0] = CRGB::Green;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Green;
  leds[5] = CRGB::Green;
  leds[6] = CRGB::Green;
  leds[7] = CRGB::Green;
  leds[8] = CRGB::Green;
  leds[9] = CRGB::Green;
  FastLED.show();
}
void Blue()
{
  M5.Lcd.setTextColor(TFT_BLUE);
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Blue;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Blue;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Blue;
  leds[8] = CRGB::Blue;
  leds[9] = CRGB::Blue;
  FastLED.show();
}
void Yellow()
{
  M5.Lcd.setTextColor(TFT_YELLOW);
  leds[0] = CRGB::Yellow;
  leds[1] = CRGB::Yellow;
  leds[2] = CRGB::Yellow;
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;
  leds[6] = CRGB::Yellow;
  leds[7] = CRGB::Yellow;
  leds[8] = CRGB::Yellow;
  leds[9] = CRGB::Yellow;
  FastLED.show();
}
void Purple()
{
  M5.Lcd.setTextColor(TFT_PURPLE);
  leds[0] = CRGB::Purple;
  leds[1] = CRGB::Purple;
  leds[2] = CRGB::Purple;
  leds[3] = CRGB::Purple;
  leds[4] = CRGB::Purple;
  leds[5] = CRGB::Purple;
  leds[6] = CRGB::Purple;
  leds[7] = CRGB::Purple;
  leds[8] = CRGB::Purple;
  leds[9] = CRGB::Purple;
  FastLED.show();
}
void Cyan()
{
  M5.Lcd.setTextColor(TFT_CYAN);
  leds[0] = CRGB::Cyan;
  leds[1] = CRGB::Cyan;
  leds[2] = CRGB::Cyan;
  leds[3] = CRGB::Cyan;
  leds[4] = CRGB::Cyan;
  leds[5] = CRGB::Cyan;
  leds[6] = CRGB::Cyan;
  leds[7] = CRGB::Cyan;
  leds[8] = CRGB::Cyan;
  leds[9] = CRGB::Cyan;
  FastLED.show();
}
