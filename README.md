# Sistemski klici
Napišite program v programskem jeziku C (ustvari.c), ki na 32 bitni arhitekturi ustvari imenik (mapa) z imenom spoimenik. Nato v programu spremenite delovno imenik na novo ustvarjeno imenik, ter v njem ustvarite zbirko (datoteko) z imenom spozbirka.txt.

Preverite, ali je zbirko spozbirka.txt dovoljeno brati in v vanjo pisati (sistemski klic access) in to informacijo izpišite na zaslon.

Spremenite stopnjo zaščite, tako da bo lahko uporabnik (user) datoteko bral in vanjo pisal, skupina (group) jo bo lahko samo brala, ostalim (others) pa bo delo z zbirko v celoti onemogočeno.

V programu je prepovedano klicati vse funkcije, razen syscall in funkcij, ki ste jih napisali sami.

Pri implementaciji si pomagajte z zgoraj podano tabelo sistemskih klicev in dokumentacijo (man).

Oddana naloga naj vsebuje:

Opozorilo: Lahko pridete do situacije, kjer z sistemskim klicom stvarite mapo ali datoteko, ne morete se pa še prestaviti v njo ali prebrati njene atribute. To se zgodi ker sama mapa ali datoteka še ni bila fizično zapisana na disk (tehnologija SSD in "caching" doprineseta k temu). V tem primeru morate še klicaty "sync" ter počakati da ukaz resnično ivede.