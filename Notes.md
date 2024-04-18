# Belangrijke info / gemaakte fouten

# Motor driver
*Gemaakt door Bas Welters.*

Voor dit project maakten we zelf een H-brug om de motors aan te sturen.
Deze H-brug is opgesteld uit MOSFETs en zou aangestuurd worden via een Attiny die op een I²C-bus aangesloten is.

Bij het ontwerpen van de H-brug koos ik echter voor de foute soort MOSFET's voor de high-side switches. Ik gebruik hiervoor NPN-MOSFET's i.p.v. PNP-MOSFET's.
Het ontwerp werkte om de motors aan te sturen maar ik kon niet genoeg spanning doorlaten omdat de gate-spanning op de high-side MOSFET's niet hoog genoeg was. (5V i.p.v. groter dan 12V).
We kozen ervoor om een pre-made H-brug te gebruiken maar het zou wel handig geweest zijn om onze eigen module te gebruiken.
Op de motor driver staan ook twee IC's om het stroomverbruik en de spanning te meten voor elke motor.

# Power-board
*Gemaakt door Bas Welters.*

Op het power-board wordt de batterijspanning omgezet naar 5v en 3.3V.
Dit doen we met LM1117T IC's.
Het bord is bedoeld om gevoedt te worden door een 3S LIPO-batterij.

Om de cellen van de batterij apart uit te meten is ook een JST-poort voorzien. Deze kan echter nog niet gebruikt worden omdat de spanning te hoog is om rechtstreeks uit te lezen met de Attiny.
Om deze poort te kunnen gebruiken zou een tussenstuk gemaakt kunnen worden met spanningsdelers om de spanning binnnen het bereik van de Attiny te brengen.
De Attiny op het power-bord kan met de ESP-32 communiceren via de I²C-bus.

# MCU
*Gemaakt door Nick Bosschaert*

Het MCU-board is de brains van de Robot Mower. Hier worden alle signalen van de sensoren ontvangen en worden alle actuatoren naar behoren aangestuurd. De microcontroller die we plaatsten op dit board is de *ESP32S3 Wroom-1-N8R8*. Dit is de chip die gebruikt wordt op het esp32s3 development board.

Aangezien er eerst voorzien was om een custom H-brug te maken en deze via I²C te verbinden waren er geen connecties voorzien om de originele H-brug te gebruiken. Er zijn echter nog wat extra IO-pins voorzien voor uitbreidingen, deze pins konden we dus gebruiken om de H-brug rechtstreeks aan te sturen met de ESP.

Alle communicatie tussen de mcu en de andere componenten zoals powerboard, hc-sr04 ultrasonic sensors, etc. wordt mogelijk gemaakt door een I²C bus. Deze bus laat ons toe om zowel berichten te ontvangen als te sturen naar geconnecteerde devices. De bus-connector bevat zowel een 5V als 3V3 pin om het gebruik van verschillende sensoren mogelijk te maken. Deze bus wordt dus ook gebruikt om de externe modules van stroom te voorzien.
De SCL en SDA lijnen van deze bus hebben zoals het hoort een pullup naar 3V3. Verbindt deze lijnen **NOOIT** met 5V, want dan zal de esp32 kortgesloten worden. Aangezien I²C werkt met een pulldown om een digitale 1 door te sturen, is dit geen probleem zolang de devices op de bus een digitale 1 lezen op een lager voltage dan 3V3.

Dit board bevat ook een USB-B connector. Deze wordt gebruikt voor het uploaden van nieuwe programmas naar de ESP32 en om gebruik te maken van de seriële monitor.

Veel sensoren en IC's werken met I²C, maar er is ook een connector voorzien voor SPI om bijvoorbeeld een SD-Card te gebruiken om data op op te slaan.

# HC-SR04 Ultrasonic Sensor
*Gemaakt door Nick Bosschaert*

Dit board zorgt ervoor dat er wat druk van de MCU afgehaald wordt door de 3 HC-SR04 afstandssensoren in te laten lezen door een ATTiny. Hierdoor kan het programma op de ESP32 verkleind en de werkdruk verlaagd worden.

De Attiny heeft zelf geen interne timer, waardoor de sensoren niet op de normale manier uitgelezen kunnen worden. Daarom wordt de "NewPing" library gebruikt, deze library laat je toe om toch een timer te gebruiken op de Attiny.
Als de MCU dan een request doet voor 11 bytes aan data, dan stuurt de ATTINY dit geformatteerd door.
Het is tot op heden nog niet mogelijk om een serial output te krijgen van de attiny, een mogelijke oplossing zou zijn om virtueel een UART poort aan te maken en deze via de UART-to-USB chip van een arduino uno of dergelijke te laten gaan.

Het pcb is heel basic met enkel het broodnodige voor de ATTiny om te kunnen draaien, de 2 I²C connectors om door te kunnen verbinden en de 3 connectors voor de HC-SR04 afstandssensoren. Behalve dan dat de lay-out verbeterd zou kunnen worden, is dit een geslaagd ontwerp.
