#include "Classes.h"

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
	direction = = {1, -1, taille,-taille};
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
	direction = = {1, -1, taille,-taille};
	table = new Pion [(taille+2)*(taille+2)];
	// On place les pions blancs de départ
	ajout_pion(4,4,0);
	ajout_pion(5,5,0);
	// On place les pions noirs de départ
	ajout_pion(4,5,1);
	ajout_pion(5,4,1);
}

Grille::~Grille(){
	delete[] table
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
	if (get(taille*i+j).couleur != -1){
		// On regarde si la case est déja occupée
		return false;
	}
	if (get(taille*(i+1)+j).couleur == 1 - couleur ||
		get(taille*(i-1)+j).couleur <= 1 - couleur ||
		get(taille*i+j+1).couleur <= 1 - couleur ||
		get(taille*i+j-1).couleur <= 1 - couleur){
		// Le placement doit se faire à coté d'un pion de couleur adverse
		return false;
	}
	// Condition lointaine de pions de meme couleur à coder
	bool cond = false;
	for(int k =0; k<3; k++){
		l = 1;
		while(get(taille*i + j + l*direction[k]).couleur == 1-couleur){
			l++;
		}
		if(get(taille*i + j + l*direction[k]).couleur == couleur){
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
			l = 1;
			while(get(taille*i + j + l*direction[k]).couleur == 1-couleur){
				l++;
			}
			if(get(taille*i + j + l*direction[k]).couleur == couleur){
				Pion p = Pion(couleur);
				for (int m =1; m<l; m++){
					set(p,taille*i + j + m*direction[k]);
				}
			}
		}
	}
	else{
		throw std::logic_error("On doit placer correctement le pion pour modifier le jeu")
	}
	return g;
}

vector<Grille> Grille::coups_possibles(int couleur){
	vector<Grille> liste_coups;
	for(int i = 0; i < taille; i++){
		for(int j = 0; j < taille; j++){
			if (test_placement(i,j,couleur)){
				liste_coup.push_back(ajout_pion(i,j,couleur));
			}
		}
	}
	return liste_coups;
}

