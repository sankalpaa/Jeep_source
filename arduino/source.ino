#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "<template id>"
#define BLYNK_TEMPLATE_NAME "<name>"
#define BLYNK_AUTH_TOKEN "<Auth token>"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "<ssid>";
char pass[] = "<password>";

BLYNK_WRITE(V1) {
  if(param.asInt() == 1) {
    turnforward(1); 
  } else {
    turnstop(1);
  }
}
BLYNK_WRITE(V2) {
  if(param.asInt() == 1) {
    turnreverse(1); 
  } else {
    turnstop(1);
  }
}
BLYNK_WRITE(V3) {
  if(param.asInt() == 1) {
    turnright(1); 
  } else {
    turnmiddle(1);
  }
}
BLYNK_WRITE(V4) {
  if(param.asInt() == 1) {
    turnLeft(1); 
  } else {
    turnmiddle(1);
  }
}

void setup() {
  // set the pins to send the output signal
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  //set the car to stop mode
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}

void loop() {
  Blynk.run();
  // turnLeft(1000);
  // turnmiddle(1000);
  // turnright(1000);
  // turnforward(1000);
  // turnstop(1000);
  // turnreverse(1000);
}

//Car turn left
void turnLeft(int delayValue) {
  digitalWrite(D0, LOW); 
  digitalWrite(D1, HIGH); 
  delay(delayValue); 
}

  //Car turn middle
void turnmiddle(int delayValue) {
  digitalWrite(D0, LOW); 
  digitalWrite(D1, LOW); 
  delay(delayValue); 
}

 //Car turn right
void turnright(int delayValue) {
  digitalWrite(D0, HIGH); 
  digitalWrite(D1, LOW); 
  delay(delayValue); 
}

//Car forward
void turnforward(int delayValue) {
  digitalWrite(D2, HIGH); 
  digitalWrite(D3, LOW); 
  delay(delayValue); 
}

//Car turn stop
void turnstop(int delayValue) {
  digitalWrite(D2, LOW); 
  digitalWrite(D3, LOW); 
  delay(delayValue); 
}

//Car reverse
void turnreverse(int delayValue) {
  digitalWrite(D2, LOW); 
  digitalWrite(D3, HIGH); 
  delay(delayValue); 
}








