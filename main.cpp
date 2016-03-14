#include "jeu.h"

int main(){
    init_table_point();

    Grille jeu;

    cout<<jeu.minmax(1,-30000,30000,true, true,64, 1, 1, 1)<<endl;

    return 0;
}
