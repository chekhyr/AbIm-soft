#include <Arduino.h>
boolean TRIG = true;
int Tblink = 150;

void blinkAbIm(int t){
  delayMicroseconds(100);
  digitalWrite(2, HIGH);
  delayMicroseconds(t);
  digitalWrite(2, LOW);
}

void setup(void){
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);  //сигнал AbIm (off) рабтает
  pinMode(3, OUTPUT);  //сингал МОЛ (off)
  pinMode(4, OUTPUT);  //сигнал CCD (on)
  pinMode(5, INPUT_PULLUP);  //кнопка
  
  digitalWrite(2, LOW);  //AbIm
  digitalWrite(3, HIGH);  //MOT
  digitalWrite(4, HIGH);  //CCD

  Serial.println("INIT complete!");
}

void loop(void){
  if(TRIG){
    digitalWrite(4, LOW);
    blinkAbIm(Tblink);
    delayMicroseconds(1000-Tblink);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);

    delay(50);
    digitalWrite(4, LOW);
    blinkAbIm(Tblink);
    delayMicroseconds(1000-Tblink);
    digitalWrite(4, HIGH);
    
    digitalWrite(3, HIGH);
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
