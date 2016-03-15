#include "jeu.h"

int main(){
    init_table_point();

    Jeu game(1,0,0,1,1,1);

    game.vsHumain(true, 64);

    return 0;
}
