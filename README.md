# S2-CreaTech

## 🎯 Projet Laser Game - Arduino
Ce projet est une mini-implémentation d’un système de Laser Game utilisant des cartes Arduino. Il comprend deux éléments principaux : un plastron porté par le joueur pour détecter les tirs, et un pistolet qui émet un signal infrarouge simulant un tir. Ce projet a aussi été accompagné de fichiers PCB pour faciliter la fabrication des circuits.

## 🧩 Composants utilisés
### Plastron (récepteur)
- Arduino (ESP32 ou compatible)
- Capteur infrarouge (IR receiver)
- Buzzer
- Écran OLED SSD1306
3 vies affichées sur l'écran
Réagit aux tirs reçus (perte de vie, son, affichage)

### Pistolet (émetteur)
- Arduino (ESP32 ou compatible)
- LED infrarouge
- Bouton-poussoir (tir)
- Buzzer
- LED témoin de tir

## ⚙️ Fonctionnement
Lorsqu’un joueur appuie sur le bouton du pistolet, un signal IR est envoyé avec un retour sonore et lumineux.
Si le plastron détecte ce signal, il réduit le nombre de vies du joueur, joue un son de tir reçu, et met à jour l’affichage sur l’écran OLED.
Quand les 3 vies sont perdues, un signal sonore de mort est émis, les vies sont réinitialisées.

## 📁 Fichiers
- PROGRAMME_LASER_GAME_PLASTRON.ino – Code du plastron (récepteur IR + affichage OLED).
- PROGRAMME_LASER_GAME_PISTOLET.ino – Code du pistolet (émission IR + feedback).
- *.svg – Fichiers PCB (plastron/pistolet) pour la fabrication des circuits imprimés.

## 🔌 Schéma de câblage
Les fichiers .svg fournis contiennent les différentes couches PCB nécessaires à la fabrication.
