#include "Classes.h"

int main(){
    init_table_point();

    Grille jeu;
    jeu.affiche();

    vector<Grille> coups = jeu.coups_possibles(1);

    cout<<coups.size()<<endl;

    return 0;
}
