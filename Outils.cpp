#include "Classes.h"


// joueur vaut 0 pour blan et 1 pour noir
// Cette fonction renvoie la valeurd'une grille pour un joueur
int Grille::score(bool joueur){
    int score = 0;
	for(int i = 1; i <= gettaille(); i++){
		for(int j = 1; j <= gettaille(); j++){
            if(get(i,j).getcouleur() == joueur){
				score += table_point[i][j];
			}
		}
	}
    return score;
}

int main(){
  return 0;
}
