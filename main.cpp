#include "Classes.h"

int main(){
    init_table_point();
    init_coefs(0,0,1.);

    Grille jeu;

    cout<<jeu.minmax(1,-30000,30000,true, true,64)<<endl;

    return 0;
}
