#include "Classes.h"

int main(){
    init_table_point();

    Grille jeu;
    jeu.affiche();

    cout<<jeu.minmax(5,-30000,30000,true)<<endl;

    return 0;
}
