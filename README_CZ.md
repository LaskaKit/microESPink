![MicroESPink](https://github.com/LaskaKit/microESPink/blob/main/img/microESPink.JPG)

# microESPink - mikro verze desky ESPink - univerzální a velmi úsporná deska s ESP32-S3 pro ePaper

MicroESPink tak doplňuje samostatnou desku, kterou máme také v nabídce [velmi úspornou a univerzální ESPink](https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/?variantId=12419). MicroESPink je menší a je také možné připojit jiné ePaper displeje. </br>

MicroESPink je založen na ESP32-S3 namísto ESP32 (větší ESPink). Místo jsme ušetřili odebráním nepoužitých GPIO pinů na okraji desky ESPink, SPI uŠup konektoru atp.</br>

Pokud preferuješ už hotový kit s přilepeným ePaper, pak máme v nabídce [Laskakit ESPink-Shelf-2.9 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-2-9-esp32-e-paper/?variantId=14193), [LaskaKit ESPink-4.2 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-42-esp32-e-paper-pcb-antenna/?variantId=13538) a [LaskaKit ESPink-Shelf-2.13 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-213-esp32-e-paper/).</br>

MicroESPink je založený na čipu ESP32-S3, který má podporu jak Wi-Fi 4, tak i Bluetooth 5.
Deska obsahuje konektor pro baterii JST-SH s roztečí 1mm. Kabel pro tento konektor [najdeš v našem e-shopu](https://www.laskakit.cz/jst-sh-2-1-0mm-2pin-konektor-s-kabelem-10cm--oboustranny/), už hotové baterie s tímto konektorem jsou pak [200mAh](https://www.laskakit.cz/geb-lipol-baterie-302040-200mah-3-7v-jst-sh-2-0/) a [400mAh](https://www.laskakit.cz/geb-lipol-baterie-303048-400mah-3-7v-jst-sh-2-0/).

Nabíjecí proud je nastaven rezistorem R11.

MicroESPink má osazený [náš univerzální I2C uŠup konektor](https://blog.laskakit.cz/predstavujeme-univerzalni-konektor-pro-propojeni-modulu-a-cidel-%CE%BCsup/) ke kterým můžeš připojit nejrůznější čidla - [SHT40 (teplota, vlhkost)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (tlak, teplota, vlhkost)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, teplota, vlhkost)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BH1750 (osvětlení)](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/), [APDS-9960 (senzor gest)](https://www.laskakit.cz/laskakit-apds-9960-senzor-priblizeni-a-gest/) a spoustu další senzorů. Náš I2C uŠup konektor je kompatibilní s Adafruit Stemma a Qwiik od Sparkfun.</br>
</br>
Deska podporuje populární projekt Živý Obraz, který výrazně zjednodušuje použití ePaper displeje k zobrazení fotografií, (google, outlook, apple) kalendáře, kurzů, hodnot z meteostanic, předpovědi počasí a mnoho dalšího. Není nutné psát kód, stačí nahrát správný typ ePaper a desky skrze webové prostředí a dodržet postup popsaný v [dokumentaci](https://wiki.zivyobraz.eu/).</br>
Program nahraješ [přes webové prostředí na této stránce](https://zivyobraz.eu/?page=instalace) a stačí zvolit desku <b>LaskaKit ESPink 3.x</b> a <b>správný typ ePaperu podle toho, který sis objednal</b>. </br>
</br>
Pokud si chceš napsat vlastní program, tak do toho :-)</br>
Na našem github máš [schéma desky](https://github.com/LaskaKit/microESPink/tree/main/HW) a nezapomněli jsme ani na [vzorové kódy](https://github.com/LaskaKit/microESPink/tree/main/SW), které by ti značně měly usnadnit programování a práci s naším microESPink. </br>
</br>
Pár technických informací:</br>
Spotřeba desky je okolo 16uA bez připojených periférií.</br>
IO piny pro I2C sběrnici jsou použity - SDA IO42 a SCL IO2.</br>
Napájení pro externí I2C čidla (uŠup), Fuel Gauge MAX17048 a ePaper je spínán přes GPIO pin 47. Aktivní v HIGH.</br>
Stav baterie je monitorován Fuel Gauge senzorem MAX17048 připojeným na stejnou I2C sběrnici. Jeho ALERT výstup je připojen k GPIO pin 9.</br>
MicroESPink má předpřipravené dva pájecí mosty, kterými se upravuje nastavení driveru na desce - popis nastavení pro ePapery najdeš ve schématu. </br>
Skrze USB-C se nabíjí jak baterie, tak probíhá i programování desky. </br>
Desku je nutné přepnout do režimu nahrávání, to provedeš tímto postupem: připojíš USB-C, zmáčkneš tlačítko FLASH a držíš, zmáčkneš a uvolníš tlačítko RESET a poté uvolníš tlačítko FLASH. </br>

## MicroESPink je k zakoupení na našem e-shopu [https://www.laskakit.cz/laskakit-microespink-esp32-s3-mini-e-paper/?variantId=17078](https://www.laskakit.cz/laskakit-microespink-esp32-s3-mini-e-paper/?variantId=17078)
