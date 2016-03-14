#include "jeu.h"

Jeu::Jeu(float c11, float c12, float c13, float c21, float c22, float c23) {
    joueur1.setCoefPos(c11);
    joueur1.setCoefMob(c12);
    joueur1.setCoefNb(c13);
    joueur2.setCoefPos(c21);
    joueur2.setCoefMob(c22);
    joueur2.setCoefNb(c23);
}

Jeu::Jeu(const Jeu &j) {
    joueur1 = j.joueur1;
    joueur2 = j.joueur2;
    world = j.world;
}

Jeu::~Jeu() {

}
