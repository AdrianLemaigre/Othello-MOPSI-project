#include "Strategie.h"

// joueur vaut 0 pour blan et 1 pour noir
// Cette fonction renvoie la valeurd'une grille pour un joueur

int table_point[10][10];

void init_table_point(){
    for(int i = 0; i<10; i++){
        for (int j; j<10; j++){
            table_point[i][j] = 0;
        }
    }
    table_point[1][1] = 99;table_point[1][2] = -8;table_point[1][3] = 8;table_point[1][4] = 6;table_point[1][5] = 6;table_point[1][6] = 8;table_point[1][7] = -8;table_point[1][8] = 99;
    table_point[2][1] = -8;table_point[2][2] = -24;table_point[2][3] = -4;table_point[2][4] = -3;table_point[2][5] = -3;table_point[2][6] = -4;table_point[2][7] = -24;table_point[2][8] = -8;
    table_point[3][1] = 8;table_point[3][2] = -4;table_point[3][3] = 7;table_point[3][4] = 4;table_point[3][5] = 4;table_point[3][6] = 7;table_point[3][7] = -4;table_point[3][8] = 8;
    table_point[4][1] = 6;table_point[4][2] = -3;table_point[4][3] = 4;table_point[4][4] = 300;table_point[4][5] = 300;table_point[4][6] = 4;table_point[4][7] = -3;table_point[4][8] = 6;
    table_point[5][1] = 6;table_point[5][2] = -3;table_point[5][3] = 4;table_point[5][4] = 300;table_point[5][5] = 300;table_point[5][6] = 4;table_point[5][7] = -3;table_point[5][8] = 6;
    table_point[6][1] = 8;table_point[6][2] = -4;table_point[6][3] = 7;table_point[6][4] = 4;table_point[6][5] = 4;table_point[6][6] = 7;table_point[6][7] = -4;table_point[6][8] = 8;
    table_point[7][1] = -8;table_point[7][2] = -24;table_point[7][3] = -4;table_point[7][4] = -3;table_point[7][5] = -3;table_point[7][6] = -4;table_point[7][7] = -24;table_point[7][8] = -8;
    table_point[8][1] = 99;table_point[8][2] = -8;table_point[8][3] = 8;table_point[8][4] = 6;table_point[8][5] = 6;table_point[8][6] = 8;table_point[8][7] = -8;table_point[8][8] = 99;
}
