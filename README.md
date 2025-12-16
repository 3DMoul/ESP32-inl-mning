# ESP32-inl-mning

Här deklarerar vi button matrixen och rgb samt newattempt som kommer användas till att hålla i inputen för att låsa upp låset.
deklarerar även LockRecord objectet och Lock objectet.

<img width="530" height="768" alt="image" src="https://github.com/user-attachments/assets/cd1ca10e-5f31-4766-85de-da0c4dec0a1d" />

I setup så sätter jag pinmode på pushknapparna samt sätter också startar färgen på RGBn.


<img width="573" height="412" alt="image" src="https://github.com/user-attachments/assets/c47b91b0-afd3-484e-8157-b2e4887d6034" />

Loopen loopar igenom readmatrix() functionen har även en while loop som håller knapptrycket så man inte får oendligt med knapptryck.

<img width="842" height="630" alt="image" src="https://github.com/user-attachments/assets/107c43ce-779f-4088-b024-0a366652503b" />

Denna function går först igenom Rows för att kolla vilken status dem är om en row är LOW(knapp nedtryckt) så checkar den vilken Colum som också är LOW(knapp nedtryckt) när man har dem så lägger man dem två indexen in i buttonmatrix arrayen så får man rätt för att om den första rowen är LOW och första Columen är LOW så kommer functionen returna '1'

Då lägger den till (+=) det in i newattempt och när antalet knapptryck(newattempt.length) är lika lika med 4 så kommer newattempt slängas in i checkLock() functionen

<img width="1140" height="801" alt="image" src="https://github.com/user-attachments/assets/4f666d4b-0ed4-432f-b400-74da13cb5569" />
<img width="767" height="626" alt="image" src="https://github.com/user-attachments/assets/105a41f7-5c9d-4602-b8b5-91d9398cbc96" />

Den kollar om kod stringen som kommer in matchar med koden som finns i Lock klassen 

<img width="727" height="215" alt="image" src="https://github.com/user-attachments/assets/c26ef382-de5a-4902-9dc8-d006a142d0ff" />

Om den matchar så kommer RGB bli grön och buzzern låter i 1 sekunder och så regestrearas upplåsningnen med object.unlockrecord() functionen och så slängs man in i en while loop som loopar tills 10 sekunder har gått eller 10k milisekunder och under detta om man håller i row[1] colum[1] = '1' i 5 sekunder så åker man in i newCode() functionen
Men om det är fel blir lampan röd och buzzern låter i 2.5 sekunder och försöket regestreras i unlockattemptRecord() functionen och den är röd i 8 sekunder och så skickas man tillbaka till main loopen

<img width="702" height="658" alt="image" src="https://github.com/user-attachments/assets/f1ce4632-0282-482e-892e-0934dbedeb5b" />
<img width="548" height="731" alt="image" src="https://github.com/user-attachments/assets/bce56e16-0c52-435d-93e4-099fcca2c385" />

Här så bytts RGB ljuset till lilla och man kan skriva en ny kod och när man har skrivit koden så måste man comfirma koden så att man vet att man inte skrev fel och när man gjort det så blir det den nya koden som låser upp låset.
