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

Grille Grille::ajout_pion(int i, int j, int couleur){
	if (i > taille || i < 1 || j > taille || j < 1){
		throw std::logic_error( "Placement hors limites" );
	}
	if (table[taille*i+j] != -1){
		throw std::logic_error( "Case déja occupée" );
	}
	if (table[taille*(i+1)+j] <= -1 || table[taille*(i-1)+j] <= -1 || table[taille*i+j+1] <= -1 || table[taille*i+j-1] <= -1){
		throw std::logic_error( "Le placement doit se faire à coté d'un pion'" );
	}
	// Condition lointaine de pions de meme couleur à coder
	if()
	Pion p = Pion(couleur);
	table[taille*i + j] = p;
}
