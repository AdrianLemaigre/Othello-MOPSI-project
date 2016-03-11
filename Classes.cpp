#include "Classes.h"

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
    table_point[4][1] = 6;table_point[4][2] = -3;table_point[4][3] = 4;table_point[4][4] = 0;table_point[4][5] = 0;table_point[4][6] = 4;table_point[4][7] = -3;table_point[4][8] = 6;
    table_point[5][1] = 6;table_point[5][2] = -3;table_point[5][3] = 4;table_point[5][4] = 0;table_point[5][5] = 0;table_point[5][6] = 4;table_point[5][7] = -3;table_point[5][8] = 6;
    table_point[6][1] = 8;table_point[6][2] = -4;table_point[6][3] = 7;table_point[6][4] = 4;table_point[6][5] = 4;table_point[6][6] = 7;table_point[6][7] = -4;table_point[6][8] = 8;
    table_point[7][1] = -8;table_point[7][2] = -24;table_point[7][3] = -4;table_point[7][4] = -3;table_point[7][5] = -3;table_point[7][6] = -4;table_point[7][7] = -24;table_point[7][8] = -8;
    table_point[8][1] = 99;table_point[8][2] = -8;table_point[8][3] = 8;table_point[8][4] = 6;table_point[8][5] = 6;table_point[8][6] = 8;table_point[8][7] = -8;table_point[8][8] = 99;
}


// Classe Pion

Pion::Pion(){
	couleur = -1;
}

Pion::Pion(int clr){
	couleur = clr;
}

void Pion::setcouleur(int y){
	couleur = y;
}

int Pion::getcouleur() const{
	return couleur;
}


//Classe Grille

Grille::Grille(){
	taille = taille_othello;
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
    table = new Pion [(taille+2)*(taille+2)];
	// On place les pions blancs de départ
	ajout_pion(4,4,0);
	ajout_pion(5,5,0);
	// On place les pions noirs de départ
	ajout_pion(4,5,1);
	ajout_pion(5,4,1);
}

Grille::Grille(int t){
	taille = t;
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
	table = new Pion [(taille+2)*(taille+2)];
	// On place les pions blancs de départ
	ajout_pion(4,4,0);
	ajout_pion(5,5,0);
	// On place les pions noirs de départ
	ajout_pion(4,5,1);
	ajout_pion(5,4,1);
}

Grille::~Grille(){
    delete[] table;
}

void Grille::settaille(int t){
	taille = t;
}

int Grille::gettaille() const{
	return taille;
}

Pion Grille::get(int i, int j){
	return table[taille*i + j];
}

Pion Grille::get(int k){
	return table[k];
}

void Grille::set(Pion p, int i, int j){
	table[taille*i + j] = p;
}

void Grille::set(Pion p, int k){
	table[k] = p;
}

bool Grille::test_placement(int i, int j, int couleur){
	if (i > taille || i < 1 || j > taille || j < 1){
		// On regarse si le placement est hors limites
		return false;
	}
    if (get(taille*i+j).getcouleur() != -1){
		// On regarde si la case est déja occupée
		return false;
	}
    if (get(taille*(i+1)+j).getcouleur() == 1 - couleur ||
        get(taille*(i-1)+j).getcouleur() <= 1 - couleur ||
        get(taille*i+j+1).getcouleur() <= 1 - couleur ||
        get(taille*i+j-1).getcouleur() <= 1 - couleur){
		// Le placement doit se faire à coté d'un pion de couleur adverse
		return false;
	}
	// Condition lointaine de pions de meme couleur à coder
	bool cond = false;
	for(int k =0; k<3; k++){
        int l = 1;
        while(get(taille*i + j + l*direction[k]).getcouleur() == 1-couleur){
			l++;
		}
        if(get(taille*i + j + l*direction[k]).getcouleur() == couleur){
			cond = true;
			Pion p = Pion(couleur);
			for (int m =1; m<l; m++){
				set(p,taille*i + j + m*direction[k]);
			}
		}
	}
	return cond;
}

Grille Grille::ajout_pion(int i, int j, int couleur){
	Grille g(taille);
	for(int a = 0; a < g.taille*g.taille; a++){
		g.set(table[a], a);
	}
	if(test_placement(i,j,couleur)){
		for(int k =0; k<3; k++){
            int l = 1;
            while(get(taille*i + j + l*direction[k]).getcouleur() == 1-couleur){
				l++;
			}
            if(get(taille*i + j + l*direction[k]).getcouleur() == couleur){
				Pion p = Pion(couleur);
				for (int m =1; m<l; m++){
					set(p,taille*i + j + m*direction[k]);
				}
			}
		}
	}
	else{
        throw std::logic_error("On doit placer correctement le pion pour modifier le jeu");
	}
	return g;
}

vector<Grille> Grille::coups_possibles(int couleur){
	vector<Grille> liste_coups;
	for(int i = 0; i < taille; i++){
		for(int j = 0; j < taille; j++){
			if (test_placement(i,j,couleur)){
                liste_coups.push_back(ajout_pion(i,j,couleur));
			}
		}
	}
	return liste_coups;
}

// int Grille::minmax (int profondeur,
// 					int alpha,
// 					int beta,
// 					bool joueur,
// 					bool etat_maxmin){
// 	if (profondeur = 0){
// 		return score(joueur);
// 	}
// 	else{
// 		vector<Grille> liste_coups = coups_possibles(joueur);
// 		"determiner les mouvements possibles" -> les mettre dans la liste fils
// 		if(liste des fils est vide){
// 			"le meme joueur rejoue"
// 			minmax(profondeur-1, grille plateaunouveau, alpha, beta, joueur, etat_maxmin)
// 		}
// 		else{
// 			for(tous les fils){
// 				if(conditions sur alpha, beta verifiées){
// 					"créer plateaunouveau"
// 					minmax(profondeur-1, grille plateaunouveau, alpha, beta, autrejoueur, nouvel_etat_maxmin)
// 					"calcul de la valeur du plateau"
// 					"modifier alpha et beta"

// 					}
// 				else{
// 					"ne rien faire"
// 				}
// 			}
// 		}
// 	}
// }
