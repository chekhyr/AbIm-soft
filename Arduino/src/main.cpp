#include <Arduino.h>
boolean trig = true;

int cameraDelay = 250;
void cameraTake(void){
  digitalWrite(4, HIGH);  //вкл сигнал камеры
  delay(50); //длина сигнала камеры
  digitalWrite(4, LOW);  //выкл сигнал камеры
  delayMicroseconds(280); //экспозиция
}

float timeAbIm = 30;
void absorptionTake(void){
  digitalWrite(2, HIGH);  //вкл AbIm
  delayMicroseconds(timeAbIm);
  digitalWrite(2, LOW);  //выкл AbIm
}

void setup(void){
  Serial.begin(9600);
  pinMode(2, OUTPUT);  //АОМ AbIm
  pinMode(3, OUTPUT);  //АОМ МОЛ
  pinMode(4, OUTPUT);  //камера
  pinMode(5, INPUT_PULLUP);  //кнопка
}

void loop(void){
  if(trig){
    digitalWrite(3, HIGH); //вкл МОЛ
    digitalWrite(2, LOW);  //выкл AbIm
    delay(500);
    
    cameraTake(); //фото атомов (+МОЛ-МОЛ+AbIm)
    digitalWrite(3, LOW);  //выкл МОЛ
    delayMicroseconds(1);
    absorptionTake();
    delay(cameraDelay);
    
    cameraTake(); //фото луча AbIm (-МОЛ+AbIm)
    absorptionTake();
    delayMicroseconds(20);
    delay(cameraDelay);    
    
    cameraTake();  //фото шума (-МОЛ-AbIm)
    delay(cameraDelay);
    
    digitalWrite(2, HIGH);  //вкл AbIm
    digitalWrite(3, HIGH);  //вкл МОЛ 
    trig = false;
  }
  else {
    if(!digitalRead(5)){
      Serial.println("Recieved TRIG");
      trig = true;
    }
  }
  delay(100);
}
