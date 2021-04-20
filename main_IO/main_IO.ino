#include "Adafruit_NeoPixel.h"

//Pinos led
#define pinLED 10 //Pino SIG da cascata de led
#define ledCount 24
Adafruit_NeoPixel strip(ledCount, pinLED, NEO_GRB + NEO_KHZ800);

#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 5
#define pinE 6
#define pinF 7

#define pinX 8
#define pinY 9
#define pinZ A0

#define pinLed 12
void setup() {
  Serial.begin(115200);
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinD, INPUT_PULLUP);
  pinMode(pinE, INPUT_PULLUP);
  pinMode(pinF, INPUT_PULLUP);

  pinMode(pinX, INPUT_PULLUP);
  pinMode(pinY, INPUT_PULLUP);
  pinMode(pinZ, INPUT);

  pinMode(pinLed, OUTPUT);

  for (int i = 0; i <= 5; i++) {
    digitalWrite(pinLed, HIGH);
    delay(100);
    digitalWrite(pinLed, LOW);
    delay(100);
  }


  strip.setBrightness(20);
  strip.begin();
  strip.show();
}

boolean ledLastState = false;

void sendDataUSB(int state, int lastState, char lowMessage, char highMessage) {
  if (state != lastState) {
    if (state == LOW) {
      Serial.write(lowMessage);

      //Controle do Led
      if (lowMessage == 'I') {
        digitalWrite(pinLed, !ledLastState);
        ledLastState = !ledLastState;
      }
      if (lowMessage == 'M') {
        digitalWrite(pinLed, HIGH);
      }

    }
    else {
      Serial.write(highMessage);

      //Controle do Led
      if (highMessage == 'N') {
        digitalWrite(pinLed, LOW);
      }
    }


    delay(10);
  }
}

int mode = 1;

int ALastState = HIGH;
int BLastState = HIGH;
int CLastState = HIGH;
int DLastState = HIGH;
int ELastState = HIGH;
int FLastState = HIGH;

int XLastState = HIGH;
int YLastState = HIGH;

int inZ = 0;
int ZLastState = 0;
int muteAux = 0;

void loop() {
  //Acelerador
  int XState = digitalRead(pinX);
  sendDataUSB(XState, XLastState, 'x', 'z');
  XLastState = XState;

  int AState = digitalRead(pinA);
  sendDataUSB(AState, ALastState, 'A', 'B');
  ALastState = AState;

  int BState = digitalRead(pinB);
  sendDataUSB(BState, BLastState, 'C', 'D');
  BLastState = BState;

  int CState = digitalRead(pinC);
  sendDataUSB(CState, CLastState, 'E', 'F');
  CLastState = CState;

  int DState = digitalRead(pinD);
  sendDataUSB(DState, DLastState, 'G', 'H');
  DLastState = DState;

  int EState = digitalRead(pinE);
  sendDataUSB(EState, ELastState, 'I', 'J');
  ELastState = EState;

  int FState = digitalRead(pinF);
  sendDataUSB(FState, FLastState, 'K', 'L');
  FLastState = FState;

  int YState = digitalRead(pinY);
  sendDataUSB(YState, YLastState, 'M', 'N');
  YLastState = YState;


  inZ = map(analogRead(pinZ), 0, 1023, 0, 100);
  if (inZ > (ZLastState + 5)) {
    ZLastState = inZ;
    Serial.write('O');
  }
  if (inZ < (ZLastState - 5)) {
    ZLastState = inZ;
    Serial.write('P');
  }

  //Muta o audio, estrutura feita para que o audio seja mutado apenas uma vez enquanto inZ for 0
  if((inZ == 0) && (muteAux == 0)){
    ZLastState = inZ;
    muteAux = 1;
    Serial.write('Q');
  }else if(inZ != 0){
    muteAux = 0;
    }

  strip.setPixelColor(0, 0, 100, 0);
  strip.setPixelColor(23, 0, 0, 100);
  strip.show();


}
