![MicroESPink](https://github.com/LaskaKit/microESPink/blob/main/img/microESPink.JPG)
# microESPink - micro version of ESPink - versatile and low power board with ESP32-S3 for ePaper/eInk

The MicroESPink thus complements the separate board we also offer, the [very low power and versatile ESPink](https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/?variantId=12419). The MicroESPink is smaller and it is also possible to connect other ePaper displays.</br>

The MicroESPink is based on the ESP32-S3 instead of the ESP32 (larger ESPink). We saved space by removing unused GPIO pins on the edge of the ESPink board, SPI usup connector etc.</br>

If you prefer a ready-to-use kit with glued ePaper, then we offer [Laskakit ESPink-Shelf-2.9 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-2-9-esp32-e-paper/?variantId=14193, [LaskaKit ESPink-4.2 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-42-esp32-e-paper-pcb-antenna/?variantId=13538) and [LaskaKit ESPink-Shelf-2.13 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-213-esp32-e-paper/).</br>

The MicroESPink is based on the ESP32-S3 chip, which has support for both Wi-Fi 4 and Bluetooth 5. The board includes a 1mm pitch JST-SH battery connector. The cable for this connector can be found [in our e-shop](https://www.laskakit.cz/jst-sh-2-1-0mm-2pin-konektor-s-kabelem-10cm--oboustranny/), and the ready-made batteries with this connector are [200mAh](https://www.laskakit.cz/geb-lipol-baterie-302040-200mah-3-7v-jst-sh-2-0/) and [400mAh](https://www.laskakit.cz/geb-lipol-baterie-303048-400mah-3-7v-jst-sh-2-0/).</br>

The charging current is set by resistor R11.</br>

MicroESPink is equipped with our[universal I2C uŠup port connector](https://blog.laskakit.cz/predstavujeme-univerzalni-konektor-pro-propojeni-modulu-a-cidel-%CE%BCsup/) to which you can connect various sensors - [SHT40 (temperature, humidity)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (pressure, temperature, humidity)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, temperature, humidity)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BH1750 (lighting)](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/), [APDS-9960 (gesture sensor)](https://www.laskakit.cz/laskakit-apds-9960-senzor-priblizeni-a-gest/) and many other sensors. </br>
Our I2C ushup connector is compatible with Adafruit Stemma and Qwiik from Sparkfun.</br>

The board supports the popular Živý Obraz project which greatly simplifies the use of ePaper displays to display photos, (google, outlook, apple) calendar, weather station readings, weather forecasts and much more. No need to write code, just upload the correct type of ePaper and board through the web environment and follow the procedure described [in the documentation](https://wiki.zivyobraz.eu/).</br>
[You upload the program through the webpage](https://zivyobraz.eu/?page=instalace) on this page and just select the <b>LaskaKit ESPink 3.x board</b> and the <b>correct ePaper type according to the one you ordered</b>.</br>

If you want to write your own program, go ahead :-)</br>
On our github you can find a [schematic](https://github.com/LaskaKit/microESPink/tree/main/HW) of the board and we have not forgotten the [sample codes](https://github.com/LaskaKit/microESPink/tree/main/SW), which should make programming and working with our microESPink much easier.</br>
</br>
Some technical information:</br>
The board consumption is around 16uA without connected peripherals.</br>
IO pins for I2C uŠup bus are used - SDA IO42 and SCL IO2.</br>
Power supply for external I2C sensors (uŠup), Fuel Gauge MAX17048 and ePaper is switched via GPIO pin 47. Active in HIGH.</br>
Battery status is monitored by the Fuel Gauge MAX17048 sensor connected to the same I2C bus. Its ALERT output is connected to GPIO pin 9.</br>
The MicroESPink has two pre-made solder bridges to adjust the driver settings on the board - see the schematic for a description of the settings for the ePapers.</br>
Both battery charging and board programming is done via USB-C.</br>
The board needs to be switched to recording mode, this is done by the following procedure: connect USB-C, press and hold the FLASH button, press and release the RESET button, then release the FLASH button.</br>
</br>
## The microESPink is available on https://www.laskakit.cz/laskakit-microespink-esp32-s3-mini-e-paper/?variantId=17078
