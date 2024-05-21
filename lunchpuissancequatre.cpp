#include "lunchpuissancequatre.h"

// Lancer le jeu via le luncheur.
void LunchPuissanceQuatre::play()
{
    this->puissanceQuatre = new PuissanceQuatre();
    this->puissanceQuatre->show();
}

LunchPuissanceQuatre::LunchPuissanceQuatre()
{
}
