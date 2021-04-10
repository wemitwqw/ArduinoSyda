# ArduinoSüda

### Eesmärk ja lühikirjeldus:
  “Süda” on seade, mis näeb välja nagu süda ning imiteerib inimese südame löömist. Selleks loeb seade sisendina infrapunast valgust, mis peegeldub liikuvast verest,   ning liigutab iga löögiga servomootorit, imiteerides sedasi pulssi. Servomootori liikumine paneb omakorda liikuma “Südame” karkassi, mis võimendab südame löömise   efekti.
  “Süda” on mõeldud kui haaravam, lõbusam ja analoogsem variant tavalistest oksimeetritest, mille eesmärk on anda parema visuaalset ettekujutus südame löömisest,     kui lihtsalt mingi graafi või numbri näitamine.

  Projekt on sündinud ja arendatud Tallinna Ülikooli Digitehnoloogia Instituudi Robootika aine raames.
  
### [Video demo](https://youtu.be/XHxEwypM9CY)
  
### Süsteemi füüsiliste komponentide ühendusskeem 
<p align=center><img src="https://cdn.discordapp.com/attachments/763628368398516235/830222038764879882/BsAAAAASUVORK5CYII.png" width="623" height="470"></p>

### Kasutatud tehnoloogiad
| <b>Seadmed</b> |
| ------ | 
| Arduino Uno | 
| KY66 Servomootor |
| SparkFun MAX30105 Particle Sensor | 
| 12 hüppajatraati |

### SparkFun MAX30105 Particle Sensor 

Meie projekti ainukeseks füüsiliseks sensoriks on “SparkFun MAX30105 Particle Sensor”, millega saab tajuda kaugust, pulssi, osakeste tuvastamist ja isegi silmapilgutamist. Meie projektis kasutame seda pulsi mõõtmiseks. Seda saavutame kasutades infrapunase valguse sensorit, mõõtes infrapuna peegelduse kogust veres väikse intervalli tagant. Siinkohal on oluline märkida, et hemoglobiinil on omadus peegeldada hästi infrapuna valgust. Tulemuste saamiseks tuleb asetada sõrme sensorile ning püsiva kontakti saavutamiseks tuleb fikseerida sõrm sensoril.

### Projekti panustajad
- Mark-Kirill Gubal
- Vladislav Priske
- Alek-Jaan Tšern

Litsents
----

MIT License

Copyright (c) 2020 Mark-Kirill Gubal, Vladislav Priske, Alek-Jaan Tšern

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
