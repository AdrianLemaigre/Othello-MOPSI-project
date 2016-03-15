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

// L'humain joue les 1, qu'il commence ou non
void Jeu::vsHumain(bool tourHumain, int coupsRestants) {
    if (coupsRestants == 0) {
        return;
    }

    if (tourHumain) {
        world.affiche();
        int posx, posy;
        std::cout<<"Entrer ligne : ";
        std::cin>>posx;
        std::cout<<endl;
        std::cout<<"Entrer colonne : ";
        std::cin>>posy;
        std::cout<<endl;

        while (!world.test_placement(posx, posy, 1)) {
            std::cout<<"Emplacement non permis !"<<endl;
            std::cout<<"Entrer ligne : ";
            std::cin>>posx;
            std::cout<<endl;
            std::cout<<"Entrer colonne : ";
            std::cin>>posy;
            std::cout<<endl;
        }

        Grille tmp = world.ajout_pion(posx, posy, 1);

        world = tmp;
        vsHumain(false, coupsRestants-1);
    } else {
        std::cout<<"Machine joue"<<endl;


    }
}
