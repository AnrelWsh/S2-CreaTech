#include <IRremote.hpp>         // Pour le capteur IR (version 4.x)
#include <Wire.h>               // Pour la communication I2C
#include <Adafruit_GFX.h>       // Pour le texte et graphismes
#include <Adafruit_SSD1306.h>   // Pour l'écran SSD1306

// Taille de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Adresse I2C de l'écran SSD1306
#define OLED_ADDRESS 0x3C

// Initialisation de l'écran
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Broche du capteur IR
int ir = 0;

// Buzzer
int buzz = 18;

// Vie
int hp = 3;

void displayHp(int hp) {
  display.clearDisplay();
  display.setTextSize(3);            // Texte grand
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.print("HP: ");
  display.print(hp);
  display.display();
}

void shotSound() {
  tone(buzz, 5000);
  delay(200);
  noTone(buzz);
}

void deathSound() {
  tone(buzz, 800);
}

void flashZero() {
  deathSound();
  delay(1000);
  noTone(buzz);
}

void setup() {
  pinMode(buzz, OUTPUT);

  // Initialisation de l'écran
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("Échec écran SSD1306"));
    for (;;); // Stop
  }

  displayHp(hp); // Affiche les vies au démarrage

  // Initialisation IR
  IrReceiver.begin(ir, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {

    if (hp > 0) {
      hp--;
      shotSound();
      displayHp(hp);

      if (hp == 0) {
        flashZero();
        hp = 3;
        displayHp(hp);
      }
    }

    IrReceiver.resume(); // prêt pour la prochaine réception
  }
}
