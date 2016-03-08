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
	table = new Pion [(taille+2)*(taille+2)];
	// On place les pions blancs de départ
	ajout_pion(4,4,0);
	ajout_pion(5,5,0);
	// On place les pions noirs de départ
	ajout_pion(4,5,1);
	ajout_pion(5,4,1);
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

Grille Grille::ajout_pion(int i, int j, int couleur){
	if (i > taille || i < 1 || j > taille || j < 1){
		throw std::logic_error( "Placement hors limites." );
	}
	if (get(taille*i+j).couleur != -1){
		throw std::logic_error( "Case déja occupée." );
	}
	if (get(taille*(i+1)+j).couleur == 1 - couleur ||
		get(taille*(i-1)+j).couleur <= 1 - couleur ||
		get(taille*i+j+1).couleur <= 1 - couleur ||
		get(taille*i+j-1).couleur <= 1 - couleur){
		throw std::logic_error( "Le placement doit se faire à coté d'un pion de couleur adverse." );
	}
	// Condition lointaine de pions de meme couleur à coder
	bool cond = true;
	for(int k =0; k<3; k++){
		l = 1;
		while(get(taille*i + j + l*direction[k]).couleur == 1-couleur){
			l++;
		}
		if(get(taille*i + j + l*direction[k]).couleur == couleur){
			cond = false;
			Pion p = Pion(couleur);
			for (int m =1; m<l; m++){
				set(p,taille*i + j + m*direction[k]);
			}
		}
	}
	if (cond){
		throw std::logic_error( "Le placement doit se faire sur une ligne conmportant un pion de sa couleur" );
	}
}
