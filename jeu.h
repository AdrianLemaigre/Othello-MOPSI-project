#ifndef JEU_H
#define JEU_H

#include "grille.h"
#include "machine.h"

class Jeu {

private:
    Machine joueur1;
    Machine joueur2;
    Grille world;

public:
    Jeu(float c11, float c12, float c13, float c21, float c22, float c23);
    Jeu(const Jeu &j);
    ~Jeu();

};

#endif
