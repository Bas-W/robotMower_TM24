# Belangrijke info / gemaakte fouten

# -Motor driver
Voor dit project maakten we zelf een H-brug om de motors aan te sturen.
Deze H-brug is opgesteld uit MOSFETs en zou aangestuurd worden via een Attiny die op een I²C-bus aangesloten is.
Bij het ontwerpen van de H-brug koos ik echter voor de foute soort MOSFET's voor de high-side switches. Ik gebruik hiervoor NPN-MOSFET's i.p.v. PNP-MOSFET's.
Het ontwerp werkte om de motors aan te sturen maar ik kon niet genoeg spanning doorlaten omdat de gate-spanning op de high-side MOSFET's niet hoog genoeg was. (5V i.p.v. >12V).
We kozen ervoor om een pre-made H-brug te gebruiken maar het zou wel handig geweest zijn om onze eigen module te gebruiken.
Op de motor driver staan ook twee IC's om het stroomverbruik en de spanning te meten voor elke motor.

# -Power-bord
Op het powerbord wordt de batterijspanning omgezet naar 5v en 3.3V.
Dit doen we met LM1117T IC's.
Het bord is bedoeld om gevoedt te worden door een 3S LIPO-batterij.

Om de cellen van de batterij apart uit te meten is ook een JST-poort voorzien. Deze kan echter nog niet gebruikt worden omdat de spanning te hoog is om rechtstreeks uit te lezen met de Attiny.
Om deze poort te kunnen gebruiken zou een tussenstuk gemaakt kunnen worden met spanningsdelers om de spanning binnnen het bereik van de Attiny te brengen.
De Attiny op het power-bord kan met de ESP-32 communiceren via de I²C-bus.
