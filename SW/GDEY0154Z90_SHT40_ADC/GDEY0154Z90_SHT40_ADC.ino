/* Example code shows values from SHT40 (temperature/humidity), battery voltage on eInk/ePaper display
 * example from libraries are used
 * 
 * Board:   LaskaKit microESPink ESP32-S3   https://www.laskakit.cz/laskakit-microespink-esp32-s3-mini-e-paper/
 * Display: Good Display GDEY0154Z90        https://www.laskakit.cz/good-display-gdey0154z90-1-54--200x200-cerveny-epaper-displej/
 * Sensor: SHT40                            https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/ is connected through uSup connector 
 * 
 * Libraries:
 * SHT40: https://github.com/adafruit/Adafruit_SHT4X
 * EPD library: https://github.com/ZinggJM/GxEPD2
 *
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */
 
#include <WiFi.h>
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include "SPI.h"
#include "Adafruit_SHT4x.h"
#include "OpenSansSB_12px.h"
#include "OpenSansSB_50px.h"
 
//MOSI/SDI    11
//CLK/SCK     12
//SS/CS       10
#define DC    48 
#define RST   45  
#define BUSY  38 
#define POWER 47
#define SDA   42
#define SCL   2

GxEPD2_3C<GxEPD2_154_Z90c, GxEPD2_154_Z90c::HEIGHT> display(GxEPD2_154_Z90c(SS, DC, RST, BUSY)); // GDEH0154Z90 200x200, SSD1681

// SHT40
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

// ADC
float vBat = 0.0;
 
void setup() {
  Serial.begin(115200);
  pinMode(POWER, OUTPUT); 
  digitalWrite(POWER, HIGH); // enable power supply for ePaper and uSup
  delay(500);

  // read ADC and calculate the voltage
  vBat = analogReadMilliVolts(34) * 1.769 / 1000; // the ratio of divider, R2=1.3M; R1=1M


  /*----------- SHT40 -----------*/
  Wire.begin(SDA,SCL);
  if (! sht4.begin()) 
  {
    Serial.println("SHT4x not found");
    Serial.println("Check connection");
    while (1) delay(1);
  }

  sht4.setPrecision(SHT4X_HIGH_PRECISION); // the higest resolution
  sht4.setHeater(SHT4X_NO_HEATER); // no heater

  sensors_event_t humidity, temperature; // variable for humidity and temperature
  sht4.getEvent(&humidity, &temperature); // read value

  Serial.print("Temperature: "); Serial.print(temperature.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  display.init(); // inicializace

  display.setRotation(3);
  display.fillScreen(GxEPD_WHITE);  // white background
  display.setTextColor(GxEPD_BLACK);  // black font

  display.setCursor(/*x*/5, /*y*/50); // set cursor
  display.setFont(&OpenSansSB_50px); // font
  display.print(String(temperature.temperature, 1)); 
  display.print("  ");
  display.print(String(humidity.relative_humidity, 0)); 

  display.setFont(&OpenSansSB_12px); // font
  display.setCursor(/*x*/30, /*y*/70); // set cursor
  display.println(" degC");
  display.setCursor(/*x*/150, /*y*/70); // set cursor
  display.println(" % Rh");

  display.setCursor(/*x*/160, /*y*/100); // set cursor
  display.print(vBat);
  display.print(" V");

  display.display(false); // update 
  delay(100);
  digitalWrite(POWER, LOW); // disable power supply for ePaper

  // deep sleep mode
  esp_sleep_enable_timer_wakeup(300 * 1000000);
  delay(200);
  esp_deep_sleep_start();
}

void loop() {}
