#pragma once
#include "Classes.h"


// joueur vaut 0 pour blan et 1 pour noir
// Cette fonction renvoie la valeurd'une grille pour un joueur
int Grille::score(Grille g, bool joueur){
	int score = 0;
	for(int i = 0; i < g.gettaille(); i++){
		for(int j = 0; j < g.gettaille(); j++){
			if(g.get(i,j).getcouleur() == joueur){
				score += table_point[i][j];
			}
		}
	}
	return score;
}

int main(){
  return 0;
}
