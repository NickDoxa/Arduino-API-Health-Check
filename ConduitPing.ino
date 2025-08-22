#include <LiquidCrystal.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include "config.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char* endpoint = API_ENDPOINT;

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

const int HTTP_TIMEOUT = 10000;
const int PING_SLEEP = 30000;
bool connected = false;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  if (!connected) {
    lcd.clear();
    lcd.print("Connecting Nano");
    connectToWifi();
    delay(2000);
    return;
  }
  bool isOnline = checkHealth();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Conduit Status:");
  lcd.setCursor(0, 1);
  if (isOnline) {
    lcd.print("API Online!");
  } else {
    lcd.print("API Offline!");
  }
  delay(PING_SLEEP);
}

bool checkHealth() {
  HTTPClient http;
  
  http.begin(endpoint);
  http.setTimeout(HTTP_TIMEOUT);
  
  http.addHeader("Content-Type", "application/json");
  http.addHeader("User-Agent", "Arduino-Monitor/1.0");
  
  int httpResponseCode = http.GET();
  if (httpResponseCode >= 200 && httpResponseCode <= 300) {
    String response = http.getString();
    if (response == "pong") {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void connectToWifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  connected = true;
}
