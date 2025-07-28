
/* Display test for Good Display GDEY0154Z90
 * example from GxEPD2 library is used
 * 
 * Board:   LaskaKit microESPink ESP32-S3   https://www.laskakit.cz/laskakit-microespink-esp32-s3-mini-e-paper/
 * Display: Good Display GDEY0154Z90        https://www.laskakit.cz/good-display-gdey0154z90-1-54--200x200-cerveny-epaper-displej/
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

// Display Library example for SPI e-paper panels from Dalian Good Display.
// Requires Adafruit_GFX and https://github.com/ZinggJM/GxEPD2 Author: Jean-Marc Zingg
// Display Library based on Demo Example from Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html

#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "bitmaps/Bitmaps3c200x200.h" // 1.54" b/w/r

#define SLEEP_SEC 15         // Measurement interval (seconds)

//MOSI/SDI    11
//CLK/SCK     12
//SS/CS       10
#define DC    48 
#define RST   45  
#define BUSY  38 
#define POWER 47

#define SLEEP_SEC 15         // Measurement interval (seconds)

GxEPD2_3C<GxEPD2_154_Z90c, GxEPD2_154_Z90c::HEIGHT> display(GxEPD2_154_Z90c(SS, DC, RST, BUSY)); // GDEH0154Z90 200x200, SSD1681

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  delay(100);

// turn on power to display
  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Display power ON");
  delay(1000);   
  //display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02
  display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
  //display.init(115200, true, 10, false, SPIn, SPISettings(4000000, MSBFIRST, SPI_MODE0)); // extended init method with SPI channel and/or settings selection
  if (display.pages() > 1)
  {
    delay(100);
    Serial.print("pages = "); Serial.print(display.pages()); Serial.print(" page height = "); Serial.println(display.pageHeight());
    delay(1000);
  }
  //display.clearScreen(); return;
  // first update should be full refresh
  drawBitmaps3c200x200();
  delay(10000);
  display.powerOff();
  Serial.println("setup done");
  display.end();
}

void loop()
{
}

struct bitmap_pair
{
  const unsigned char* black;
  const unsigned char* red;
};

void drawBitmaps3c200x200()
{
  bitmap_pair bitmap_pairs[] =
  {
    //{Bitmap3c200x200_black, Bitmap3c200x200_red},
    {WS_Bitmap3c200x200_black, WS_Bitmap3c200x200_red}
  };
  if (display.epd2.hasColor)
  {
    display.clearScreen(); // use default for white
    int16_t x = (int16_t(display.epd2.WIDTH) - 200) / 2;
    int16_t y = (int16_t(display.epd2.HEIGHT) - 200) / 2;
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.drawImage(bitmap_pairs[i].black, bitmap_pairs[i].red, x, y, 200, 200, false, false, true);
      delay(2000);
    }
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      int16_t x = -60;
      int16_t y = -60;
      for (uint16_t j = 0; j < 10; j++)
      {
        display.writeScreenBuffer(); // use default for white
        display.writeImage(bitmap_pairs[i].black, bitmap_pairs[i].red, x, y, 200, 200, false, false, true);
        display.refresh();
        delay(1000);
        x += display.epd2.WIDTH / 4;
        y += display.epd2.HEIGHT / 4;
        if ((x >= int16_t(display.epd2.WIDTH)) || (y >= int16_t(display.epd2.HEIGHT))) break;
      }
    }
    display.writeScreenBuffer(); // use default for white
    display.writeImage(bitmap_pairs[0].black, bitmap_pairs[0].red, 0, 0, 200, 200, false, false, true);
    display.writeImage(bitmap_pairs[0].black, bitmap_pairs[0].red, int16_t(display.epd2.WIDTH) - 200, int16_t(display.epd2.HEIGHT) - 200, 200, 200, false, false, true);
    display.refresh();
    delay(2000);
  }
}