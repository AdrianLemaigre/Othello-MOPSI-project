#include "jeu.h"

int main(){
    init_table_point();

    Jeu game;

    game.vsMachine(true, 64, 0);
    cout<<game.gagne()<<" a gagné !"<<endl;

    game.clear();
    game.vsMachine(true, 64, 0);
    cout<<game.gagne()<<" a gagné !"<<endl;

    return 0;
}
