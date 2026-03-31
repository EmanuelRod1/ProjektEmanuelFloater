# 1. Kalibracija

## Problem

Prilikom testiranja uspostavljene touch funkcionalnosti ekrana, opazilo se kako koordinate dodira se nakon nekog vremena zamrznu. Dakle, koordinata x bi znala zapesti na vrijednosti 240, dok bi koordinata y znala zapesti na vrijednosti 30.
Kada se pokušao ekran kalibrirati, primjetilo se kako se ta pojava zamrzavanja koordinata pojavljuje isto i kod sirovih vrijednosti koordinata.
Isprva se pretpostavilo da kalibracija koja se koristi za ovaj ekran nije trivijalna te je potrebno iskoristiti neku složeniju kalibraciju koja nije nužno linearna.

## Predložak rješenja

Prvobitan prijedložak rješenja bio je implementirati u kod biblioteku kompatibilnu za TFT28-105 ekran koji se još uvijek koristi tijekom razvoja aplikacije. [Biblioteka se može skinuti s ove poveznice.](https://os.mbed.com/users/displaymodule/notebook/dm-tft28-105/)
Stranica sadrži primjere i solucije za korištenje touch funkcije za navedeni ekran.

## Pokušaj kalibracije

Prvi pokušaj kalibracije bio je podesiti moguće ekstreme x i y koordinata čitajući sirove vrijednosti prilikom dodira na gornje i donje kutove ekrana.
Ubrzo se uspostavilo da to nije solucija problema lošeg očitavanja vrijednosti ekrana.
Nakon testiranja s mijenjanjem drivera (promijenio sam driver za XPT2046 koristeći [ovaj kod](https://github.com/taburyak/STM32-touchscreen-XPT2046-HAL-SPI/tree/master).) 

