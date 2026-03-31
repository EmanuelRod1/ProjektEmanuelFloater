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
Unatoč tome, ekran je rijetko radio kako treba i opet se pojavljivao problem zamrzavanaj vrijednosti.

## Mogući problemi

Jedna mougćnost koja je mogla biti razlog ovome je utrka između xpt2046 i ili9341 drivera koji su se takmičili za SPI sučelje.
Ali, uspostavilo se da to ne može biti jer, nakon što sam maknuo display task iz koda, isti se problem javljao.
Iako, nakon testiranja, primjetio sam kako se koordinate odmrzavaju nakon što pločicu držim u blago zakrivljenoj šaci. 
Pretpostavljam da se radi o tome što ja stvaram nekakvo uzemljenje čime smanjujem šum očitavanja i dobivam približno točne vrijednosti.
Dakle, moguće je da nije problem u sfotware-u već u hardware-u.
Također, kada se drži pločica u ruci i pomći olovka po ekranu, mogu se naići na područja ekrana gdje koordinate "skaču" na vrijednosti koje nisu nimalo blizu onima koje bi trebale biti. Pretpostavljam da se radi o tome što moguć problem u hardware-u uzrokuje jako loše očitavanje podataka i kada nisu zamrznuti.

## Neka linkovi

Naišao sam na određene izvore koji bi bili moguće korisni za ovaj problem:
* https://github.com/maudeve-it/ILI9XXX-XPT2046-STM32
* https://cdn.shopify.com/s/files/1/0264/7629/files/XPT2046.pdf
* https://community.st.com/t5/stm32-mcus-products/why-spi-returns-busy-after-a-while-of-sending-correctly/td-p/198801
* https://github.com/robert-hh/XPT2046-touch-pad-driver/issues/5
* https://ask.embedded-wizard.de/6368/xpt2046-and-other-touch-issues
