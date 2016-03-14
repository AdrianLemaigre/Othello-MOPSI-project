#include "Classes.h"

int main(){
    init_table_point();

    Grille jeu;

    cout<<jeu.minmax(7,-30000,30000,true, true,64)<<endl;

    return 0;
}
