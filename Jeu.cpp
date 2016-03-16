#include "jeu.h"

Jeu::Jeu() {

}

Jeu::Jeu(Machine j1, Machine j2) {
    joueur1 = j1;
    joueur2 = j2;
}

Jeu::Jeu(const Jeu &j) {
    joueur1 = j.joueur1;
    joueur2 = j.joueur2;
    world = j.world;
}

Jeu::~Jeu() {

}

// L'humain joue les 1, qu'il commence ou non
void Jeu::vsHumain(bool tourHumain, int coupsRestants, int coupsPasses) {
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
        vsHumain(false, coupsRestants-1, coupsPasses+1);
    } else {
        std::cout<<"Machine joue"<<endl;

        vector<Grille> coupsPossibles = world.coups_possibles(0);
        Grille meilleur;
        int meilleurScore = -30000;

        for (int i = 0; i < coupsPossibles.size(); i++) {
            int mm = world.minmax(5, -30000, 30000, false, false, coupsRestants,
                                   joueur2.getCoefPos(coupsPasses),
                                   joueur2.getCoefMob(coupsPasses),
                                   joueur2.getCoefNb(coupsPasses));
            if (meilleurScore < mm) {
                meilleur = coupsPossibles[i];
                meilleurScore = mm;
            }
        }
        world = meilleur;
        vsHumain(true, coupsRestants-1,coupsPasses+1);
    }
}

// A verifier
void Jeu::vsMachine(bool tourMachine1, int coupsRestants, int coupsPasses) {
    if (coupsRestants != 0) {

        if (tourMachine1) {
            vector<Grille> coupsPossibles1 = world.coups_possibles(1);
            Grille meilleur1(world);
            int meilleurScore1 = -30000;

            for (int i = 0; i < coupsPossibles1.size(); i++) {
                int mm1 = coupsPossibles1[i].minmax(2, -30000, 30000, true, true, coupsRestants,
                                       joueur1.getCoefPos(coupsPasses),
                                       joueur1.getCoefMob(coupsPasses),
                                       joueur1.getCoefNb(coupsPasses));
                if (meilleurScore1 < mm1) {
                    meilleur1 = coupsPossibles1[i];
                    meilleurScore1 = mm1;
                }
            }
            world = meilleur1;
            vsMachine(false, coupsRestants-1,coupsPasses+1);
        } else {
            vector<Grille> coupsPossibles2 = world.coups_possibles(0);
            Grille meilleur2(world);
            int meilleurScore2 = -30000;

            for (int i = 0; i < coupsPossibles2.size(); i++) {
                int mm2 = coupsPossibles2[i].minmax(2, -30000, 30000, false, false, coupsRestants,
                                       joueur2.getCoefPos(coupsPasses),
                                       joueur2.getCoefMob(coupsPasses),
                                       joueur2.getCoefNb(coupsPasses));
                if (meilleurScore2 < mm2) {
                    meilleur2 = coupsPossibles2[i];
                    meilleurScore2 = mm2;
                }
            }
            world = meilleur2;
            vsMachine(true, coupsRestants-1,coupsPasses+1);
        }
    }
}

int Jeu::gagne() {
    int score0 = 0;
    int score1 = 0;

    for (int i = 0; i < world.gettaille()*world.gettaille(); i++) {
        if (world.get(i).getcouleur() == 0)
            score0++;
        else if (world.get(i).getcouleur() == 1)
            score1++;
    }

    if (score0 > score1)
        return 0;
    else
        return 1;
}

void Jeu::clear() {
    Grille g(world.gettaille() - 2);
    world = g;
}
