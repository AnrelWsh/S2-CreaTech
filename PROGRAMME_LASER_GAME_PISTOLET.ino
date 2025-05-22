#include <IRremote.hpp>

const int irLedPin = 2;
const int ledPin = 1;
const int buttonPin = 21;
const int buzzerPin = 22;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  IrSender.setSendPin(irLedPin);
  IrSender.enableIROut(38); // 38 kHz standard IR

  Serial.begin(115200);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 5000);
    delay(100);
    noTone(buzzerPin);
    delay(100);

    IrSender.sendNEC(0xFF, 0x00, 2);  // 2 répétitions pour fiabiliser
    Serial.println("Signal IR envoyé : adresse=0xFF, commande=0x00");

    digitalWrite(ledPin, LOW);
    delay(300);
  }
}
