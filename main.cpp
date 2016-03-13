#include "Classes.h"

int main(){
    init_table_point();

    Grille jeu;

    cout<<jeu.minmax(2,-30000,30000,true, true)<<endl;

    return 0;
}
