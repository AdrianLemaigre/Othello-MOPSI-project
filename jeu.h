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
    Jeu();
    Jeu(Machine j1, Machine j2);
    Jeu(const Jeu &j);
    ~Jeu();

    void vsHumain(bool tourHumain, int coupsRestants, int coupsPasses);
    void vsMachine(bool tourMachine1 int coupsRestants, int coupsPasses);
    int gagne();

};

#endif
