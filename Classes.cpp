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
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
    direction[4] = 1 + taille;
    direction[5] = 1 -taille;
    direction[6] = -1 +taille;
    direction[7] = -1 -taille;
    table = new Pion [(taille+2)*(taille+2)];
    // On place les pions blancs de départ
    set(Pion(0),4,4);
    set(Pion(0),5,5);
	// On place les pions noirs de départ
    set(Pion(1),4,5);
    set(Pion(1),5,4);
    // On initialise les cases des bords à -2
    for(int i = 0; i < taille+2; i++){
	    set(Pion(-2),0,i);
	    set(Pion(-2),i,0);
	    set(Pion(-2),taille + 1,i);
	    set(Pion(-2),i,taille + 1);
	}
}

Grille::Grille(int t){
	taille = t;
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
    direction[4] = 1 + taille;
    direction[5] = 1 -taille;
    direction[6] = -1 +taille;
    direction[7] = -1 -taille;
	table = new Pion [(taille+2)*(taille+2)];
	// On place les pions blancs de départ
    set(Pion(0),4,4);
    set(Pion(0),5,5);
	// On place les pions noirs de départ
    set(Pion(1),4,5);
    set(Pion(1),5,4);
    // On initialise les cases des bords à -2
    for(int i = 0; i < taille+2; i++){
	    set(Pion(-2),0,i);
	    set(Pion(-2),i,0);
	    set(Pion(-2),taille + 1,i);
	    set(Pion(-2),i,taille + 1);
	}
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
	return table[(taille+2)*i + j];
}

Pion Grille::get(int k){
	return table[k];
}

void Grille::set(Pion p, int i, int j){
	table[(taille+2)*i + j] = p;
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
	for(int k =0; k<8; k++){
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
		for(int k =0; k<8; k++){
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

int Grille::minmax (int profondeur,
					int alpha,
					int beta,
                    bool joueur){
    if (profondeur == 0){
        return score(joueur);
	}
    if (joueur){
        int v = -300000;
		vector<Grille> liste_coups = coups_possibles(joueur);
		if(liste_coups.size() == 0){
            //le meme joueur rejoue
			// A voir
            minmax(profondeur-1, alpha, beta, !joueur);
		}
		else{
			for(int i = 0; i < liste_coups.size(); i ++){
                v = max(v, liste_coups[i].minmax(profondeur - 1, alpha, beta, !joueur));
                alpha = max(alpha, v);
				if(beta <= alpha){
					break;
				}
			}
			return v;
		}
    } else {
        int v = 300000;
		vector<Grille> liste_coups = coups_possibles(joueur);
		if(liste_coups.size() == 0){
            //"le meme joueur rejoue"
			// A voir
            minmax(profondeur - 1, alpha, beta, !joueur);
		}
		else{
			for(int i = 0; i < liste_coups.size(); i ++){
                v = min(v, liste_coups[i].minmax(profondeur - 1, alpha, beta, !joueur));
                alpha = min(beta, v);
				if(beta <= alpha){
					break;
				}
			}
			return v;
        }
    }

    return 0;
}

void Grille::affiche() {
    for (int i=0; i<taille+2; i++) {
        for (int j=0; j<taille+2; j++) {
            cout<<get(i,j).getcouleur()<<" ";
        }
        cout<<endl;
    }
}
