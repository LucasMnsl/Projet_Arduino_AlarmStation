# Station Alarme - Projet Arduino

## Table des Matières
- [Objectif du Projet](#objectif-du-projet)
- [Fonctionnement](#fonctionnement)
  - [Matériel Utilisé](#matériel-utilisé)
  - [Navigation et Configuration](#navigation-et-configuration)
- [Fonctionnement des Classes](#fonctionnement-des-classes)
  - [Classe `Capteur`](#classe-capteur)
  - [Classe `CapteurRanger`](#classe-capteurranger-hérite-de-capteur)
  - [Classe `CapteurSon`](#classe-capteurson-hérite-de-capteur)
  - [Classe `BUZZER`](#classe-buzzer)
  - [Classe `LED`](#classe-led)
  - [Classe `MENU`](#classe-menu)
- [Installation et Utilisation](#installation-et-utilisation)

## Objectif du Projet

Ce projet consiste à développer une station alarme destinée à détecter les intrusions dans une maison en l'absence des habitants. L'alarme est équipée d'une interface utilisateur intuitive à l'aide d'un écran LCD et propose des fonctionnalités de personnalisation, telles que la configuration des signaux d'alerte et des paramètres visuels. 

## Fonctionnement

La station alarme repose sur les composants suivants :

### Matériel Utilisé
- **Arduino ESP8266** : Microcontrôleur principal exécutant le code.
- **Buzzer** : Émet un signal sonore en alternant entre deux fréquences (signal d'alarme).
- **LED** : Émet un signal lumineux clignotant (signal d'alarme).
- **Écran LCD** : Affiche les menus de configuration et d'état de l'alarme.
- **Boutons** : Permettent de naviguer et de sélectionner les options du menu.
- **Capteur sonore** : Mesure l'intensité sonore pour détecter une intrusion.
- **Capteur ultrasonique** : Mesure les distances pour détecter une intrusion.

### Navigation et Configuration
Le menu interactif permet :
- De régler les paramètres du buzzer (fréquences et délais).
- De configurer les délais d'activation de la LED.
- De personnaliser les couleurs et la luminosité de l'écran LCD.
- De définir les seuils pour les capteurs (sonore et ultrasonique).
- De tester les différents composants (buzzer, LED, capteurs).
- D'activer le mode alarme pour surveiller les intrusions.

Le bouton est utilisé pour naviguer entre les options, tandis que le capteur capacitif permet de valider les sélections.

## Fonctionnement des Classes

Le projet est organisé en plusieurs classes, chacune encapsulant la logique spécifique à un composant ou une fonctionnalité. Voici un récapitulatif :

### Classe `Capteur`
Classe de base pour les capteurs.
- **Attributs :**
  - `etat` : Indique l'état du capteur (0 ou 1).
  - `nombre_capteur` : Nombre total de capteurs créés (statique).
- **Méthodes :**
  - **`lire_etat()`** : Retourne l'état actuel du capteur (0 ou 1).
  - **`reset()`** : Réinitialise l'état du capteur.
  - **`lire_nombre_capteur()`** : Retourne le nombre total de capteurs créés.

### Classe `CapteurRanger` (Hérite de `Capteur`)
Gère un capteur ultrasonique pour mesurer les distances.
- **Attributs :**
  - `distance` : Distance mesurée par le capteur ultrasonique.
  - `limit` : Limite de distance pour déclencher le capteur.
  - `port` : Port utilisé par le capteur.
- **Méthodes :**
  - **`CapteurRanger(int l, int p)`** : Initialise le capteur avec une limite et un port.
  - **`lire_port()`** : Retourne le port utilisé par le capteur.
  - **`lire_distance()`** : Retourne la distance mesurée par le capteur.
  - **`check_etat(Ultrasonic *U)`** : Met à jour l'état du capteur en fonction de la distance mesurée.
  - **`set_limit(int new_limit)`** : Définit une nouvelle limite de distance.
  - **`lire_limit()`** : Retourne la limite actuelle de distance.

### Classe `CapteurSon` (Hérite de `Capteur`)
Gère un capteur sonore pour mesurer l'intensité sonore.
- **Attributs :**
  - `sound` : Valeur sonore mesurée.
  - `limit` : Limite sonore pour déclencher le capteur.
  - `pinson` : Pin associé au capteur sonore.
- **Méthodes :**
  - **`CapteurSon(int l, int pin)`** : Initialise le capteur avec une limite sonore et un port.
  - **`lire_sound()`** : Retourne la valeur sonore mesurée.
  - **`check_etat()`** : Met à jour l'état du capteur en fonction de la valeur sonore mesurée.
  - **`set_limit(int new_limit)`** : Définit une nouvelle limite sonore.
  - **`lire_limit()`** : Retourne la limite actuelle sonore.

### Classe `BUZZER`
Gère le fonctionnement du buzzer.
- **Attributs :**
  - `etat` : État actuel du buzzer (actif/inactif).
  - `pinBUZZER` : Broche associée au buzzer.
  - `freq1` : Première fréquence configurée pour le buzzer.
  - `freq2` : Deuxième fréquence configurée pour le buzzer.
  - `delai` : Délai d'alternance entre les fréquences.
  - `isFreq1` : Indique si la fréquence actuelle est `freq1` ou `freq2`.
  - `lastMillis`, `currentMillis` : Utilisés pour gérer le timing.
- **Méthodes :**
  - **`BUZZER()`** : Constructeur par défaut (broche 14, fréquences par défaut de 800 Hz et 1200 Hz).
  - **`BUZZER(int pin)`** : Constructeur avec spécification de la broche.
  - **`getFreq1()`**, **`getFreq2()`** : Retourne les fréquences configurées.
  - **`getDelai()`** : Retourne le délai d'alternance.
  - **`setFreq1(int f)`**, **`setFreq2(int f)`** : Modifie les fréquences.
  - **`setDelai(int t)`** : Modifie le délai.
  - **`turnOn()`**, **`turnOff()`** : Active ou désactive le buzzer.

### Classe `LED`
Gère le fonctionnement de la LED.
- **Attributs :**
  - `etat` : État actuel de la LED (activée/désactivée).
  - `pinLED` : Broche associée à la LED.
  - `delai` : Délai pour l'état haut de la LED.
  - `isHigh` : Indique si la LED est à l'état haut ou bas.
  - `lastMillis`, `currentMillis` : Utilisés pour gérer le timing.
- **Méthodes :**
  - **`LED()`**, **`LED(int pin)`** : Constructeurs (LED par défaut ou spécifiée).
  - **`getDelai()`** : Retourne le délai de clignotement.
  - **`setDelai(int t)`** : Définit un nouveau délai.
  - **`turnOn()`**, **`turnOff()`** : Active ou désactive la LED.

### Classe `MENU`
Gère l'interface utilisateur et l'affichage sur l'écran LCD.
- **Attributs :**
  - `monLCD` : Instance pour contrôler l'écran LCD.
  - `pinB1`, `pinB2` : Broches des boutons associés au menu.
  - `etat` : État interne du menu.
  - `Luminosity` : Niveau de luminosité actuel de l'écran LCD.
  - `couleurLCD` : Couleur actuelle affichée sur l'écran LCD.
  - `colors` : Liste des couleurs prédéfinies avec leurs valeurs RGB.
  - `Luminosities` : Liste des niveaux de luminosité prédéfinis.
  - `numLum`, `numCoul` : Indices actuels des luminosités et couleurs.
  - `currentValueB1`, `pastValueB1`, `currentValueB2`, `pastValueB2` : État actuel et précédent des boutons.
- **Méthodes :**
  - **`MENU()`**, **`MENU(int pin1, int pin2)`** : Constructeurs avec ou sans spécification des boutons.
  - **`afficherMenu()`** : Affiche les paramètres actuels des composants sur l'écran LCD.
  - **`checkButtons()`** : Vérifie l'état des boutons et met à jour le menu en conséquence.
  - **`setRGBLCD(std::string couleur)`** : Modifie la couleur RGB de l'écran LCD en fonction d'une couleur prédéfinie.

## Installation et Utilisation
1. Connectez les composants à votre carte Arduino selon les ports spécifiés dans le code.
2. Téléversez le programme sur la carte.
3. Naviguez dans le menu pour configurer et tester les différents composants.
4. Activez l'alarme pour détecter les intrusions.

---

Ce projet combine une interface intuitive avec une architecture logicielle modulaire pour un système d'alarme personnalisable et extensible.

