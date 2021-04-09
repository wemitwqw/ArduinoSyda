//Lisame kolm järgmist library't
#include <Wire.h> 
#include "MAX30105.h"
#include <Servo.h>

MAX30105 particleSensor; // deklareerime sensori objekti

Servo servo; // deklareerime servo objekti
int minAngle = 11; // servo minimaalne nurk
int maxAngle = 41; //servo maksimaalne nurk
int ServoTestNew = 0; //muutuja, mis läheb tarvis erinevate IR(infrapunaste) väärtuste võrdlemiseks
int ServoTestOld = 0; //muutuja, mis läheb tarvis erinevate IR(infrapunaste) väärtuste võrdlemiseks
int difference = 0;  //Vahe muutujate ServoTestNew ja ServoTestOld vahel

void setup() //Siis kui käivitatakse esmakordselt
{
  servo.attach(4); //lisame servo objekti digitaalse sisendiga "4"

  Serial.begin(115200); //Määrame baudi suurust Serial Plotteri jaoks
  Serial.println("Initializing...");

  // Käivitame sensorit
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Kasutame vaikimiselt I2C porti, 400kHz kiirust
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. "); //Viga teadeanne, juhul Serial ei leia sensorit
    while (1);
  }

  //Seadistame Sparkfun max30105 sensorit
  byte ledBrightness = 0x1F; //Options: 0=Off to 255=50mA //seadistame LEDi kirguse tugevust
  byte sampleAverage = 8; //Options: 1, 2, 4, 8, 16, 32 // seadistame näidiste arvu
  byte ledMode = 3; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green //seadistame LEDi värvuse varianti
  int sampleRate = 200; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200 //seadistame näidistevahelist ajavahemiku
  int pulseWidth = 411; //Options: 69, 118, 215, 411 // seadistame sensori pulside laiust
  int adcRange = 4096; //Options: 2048, 4096, 8192, 16384 // seadistame piiranguid analooglugeja pingetundlikusele

  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Seadistame sensorit vastavate seadmetega

  //võtame keskmiselt nii palju IR sisendeid plotteri (graafi) jaoks
  const byte avgAmount = 64; 
  long baseValue = 0;
  for (byte x = 0 ; x < avgAmount ; x++)
  {
    baseValue += particleSensor.getIR(); //Loeb IR väärtuse
  }
  baseValue /= avgAmount;

  // Eeltäidame plotteri nii, et Y telg oleks IR väärtustele lähem 
  for (int x = 0 ; x < 500 ; x++)
    Serial.println(baseValue); // Prindib baasväärtusi välja
}

void loop()
{
  ServoTestNew = particleSensor.getIR(); //anname muutujale uut IR sisendit
  difference = abs(ServoTestNew - ServoTestOld); //arvutame ServoTestNew ja ServoTestOld vahe absoluutväärtust
  if (difference <  2500){
    Serial.println(ServoTestNew); //Kui vahe on vähem kui 2500, siis paneme plotteris kirja uut IR väärtust
  }
  if(difference>190){ //Juhul kui vahe on rohkem kui 190 
    if (ServoTestNew > ServoTestOld) { //Juhul kui vahe on positiivne, siis...
        servo.write(maxAngle); //Servomootor vahetab enda pöördenurga positsioonise maxAngle
        ServoTestOld = ServoTestNew; //salvestab uut positsiooni, et hiljem võrrelda veel uuemaga
    } else if(ServoTestOld > ServoTestNew) { //Juhul kui vahe on negatiivne, siis...
        servo.write(minAngle); //Servomootor vahetab enda pöördenurga positsioonise minAngle
        ServoTestOld = ServoTestNew; //salvestab uut positsiooni, et hiljem võrrelda veel uuemaga
    } 
  } 
}
