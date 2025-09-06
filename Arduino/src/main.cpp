#include <Arduino.h>
boolean TRIG = true;

void blinkAbIm(int t){
  digitalWrite(2, HIGH);
  delayMicroseconds(t);
  digitalWrite(2, LOW);
}

void setup(void){
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);  //сигнал AbIm
  pinMode(3, OUTPUT);  //сингал МОЛ
  pinMode(4, OUTPUT);  //сигнал CCD
  pinMode(5, INPUT_PULLUP);  //кнопка
  
  digitalWrite(2, LOW);  //AbIm off
  digitalWrite(3, HIGH);  //MOT on
  digitalWrite(4, HIGH);  //CCD on

  Serial.println("INIT complete!");
}

int Tblink = 10;
int EXPdelay = 200; // should be around 62us
// see https://www.thorlabs.us/Thorcat/15900/15982-D02/index.html
void loop(void){
  if(TRIG){
    digitalWrite(4, LOW); //CCD trig
    delayMicroseconds(EXPdelay); //waiting for the exposure start
    
    digitalWrite(3, LOW); //MOT off
    blinkAbIm(Tblink); //AbIm

    delay(50);
    digitalWrite(4, HIGH); //CCD reload
    delay(50);

    digitalWrite(4, LOW); //CCD trig
    delayMicroseconds(EXPdelay); //waiting for the exposure start
    blinkAbIm(Tblink); //AbIm
    
    delay(50);
    digitalWrite(4, HIGH); //CCD reload
    delay(50);

    digitalWrite(4, LOW); //CCD trig
    delayMicroseconds(EXPdelay); //waiting for the exposure start

    delay(50);
    digitalWrite(4, HIGH); //CCD reload
    digitalWrite(3, HIGH); //MOT on
    TRIG = false;
  }
  else{
    if(!digitalRead(5)){
          Serial.println("received TRIG");
          TRIG = true;    
    }
  }
  delay(100);
}
