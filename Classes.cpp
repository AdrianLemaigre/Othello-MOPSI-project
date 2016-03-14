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

Grille::Grille(int t){
    taille = t+2;
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
    direction[4] = 1 + taille;
    direction[5] = 1 -taille;
    direction[6] = -1 +taille;
    direction[7] = -1 -taille;
    table = new Pion [taille*taille];
    // On place les pions blancs de départ
    set(Pion(0),4,4);
    set(Pion(0),5,5);
	// On place les pions noirs de départ
    set(Pion(1),4,5);
    set(Pion(1),5,4);
    // On initialise les cases des bords à -2
    for(int i = 0; i < taille; i++){
	    set(Pion(-2),0,i);
	    set(Pion(-2),i,0);
        set(Pion(-2),taille - 1,i);
        set(Pion(-2),i,taille - 1);
    }
}

Grille::Grille(const Grille& g) {
    taille = g.taille;
    table = new Pion [taille*taille];
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = taille;
    direction[3] = -taille;
    direction[4] = 1 + taille;
    direction[5] = 1 -taille;
    direction[6] = -1 +taille;
    direction[7] = -1 -taille;

    for (int i = 0; i<taille*taille; i++) {
        table[i] = g.table[i];
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
    if (get(i,j).getcouleur() != -1) {
		// On regarde si la case est déja occupée
        return false;
    }

    bool cond = false;
	for(int k =0; k<8; k++){
        int l = 1;
        while(get(taille*i + j + l*direction[k]).getcouleur() == 1-couleur){
			l++;
		}
        if (get(taille*i + j + l*direction[k]).getcouleur() == couleur && l>1){
			cond = true;
		}
	}
    return cond;
}

Grille Grille::ajout_pion(int i, int j, int couleur){
    Grille g(taille-2);
    for(int a = 0; a < g.taille*g.taille; a++){
		g.set(table[a], a);
	}
    g.set(Pion(couleur),i,j);

    for(int k =0; k<8; k++){
        int l = 1;
        while(get(taille*i + j + l*direction[k]).getcouleur() == 1-couleur){
            l++;
        }
        if(get(taille*i + j + l*direction[k]).getcouleur() == couleur){
            Pion p = Pion(couleur);
            for (int m = 1; m<l; m++){
                g.set(p,taille*i + j + m*direction[k]);
            }
        }
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

int Grille::score(bool joueur){
    return int(coef_pos*score_pos(joueur) + coef_mob*score_mob(joueur) + coef_nb*score_nb(joueur));
}

int Grille::score_pos(bool joueur){
    int score = 0;
    for(int i = 1; i < taille; i++){
        for(int j = 1; j < taille; j++){
            if(get(i,j).getcouleur() == joueur){
                score += table_point[i][j];
            } else if (get(i,j).getcouleur() == 1 - joueur) {
                score -= table_point[i][j];
            }
        }
    }
    return score;
}

int Grille::score_mob(bool joueur){
    int compteur = 0;
    for(int i = 0; i < taille-1; i++){
        for(int j = 0; j < taille-1; j++){
		    if (get(i,j).getcouleur() != -1) {
				// On regarde si la case est déja occupée
                continue;
            }

			// Condition lointaine de pions de meme couleur à coder
            bool cond = false;
			for(int k =0; k<8; k++){
		        int l = 1;
                while(get(taille*i + j + l*direction[k]).getcouleur() == 1 - joueur){
					l++;
				}
                if (get(taille*i + j + l*direction[k]).getcouleur() == joueur && l>1){
                    cond = true;
                    break;
				}
			}
            if (cond){
		    	compteur += 1;
		    }
		}
	}
    return compteur;
}

int Grille::score_nb(bool joueur){
    int score = 0;
    for(int i = 1; i < taille; i++){
        for(int j = 1; j < taille; j++){
            if(get(i,j).getcouleur() == joueur){
                score += 1;
            }
        }
    }
    return score;
}

int Grille::minmax (int profondeur,
					int alpha,
					int beta,
                    bool joueur,
                    bool cible,
                    int coupsRestants){

    if (profondeur == 0 || coupsRestants == 0){
        return score(cible);
	}
    if (joueur == cible){
        int v = -300000;
		vector<Grille> liste_coups = coups_possibles(joueur);
		if(liste_coups.size() == 0){
            //le meme joueur rejoue
            return minmax(profondeur-1, alpha, beta, !joueur, cible, coupsRestants-1);
		}
		else{
			for(int i = 0; i < liste_coups.size(); i ++){
                v = max(v, liste_coups[i].minmax(profondeur - 1, alpha, beta, !joueur, cible,coupsRestants-1));
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
            return minmax(profondeur - 1, alpha, beta, !joueur, cible, coupsRestants-1);
		}
		else{
			for(int i = 0; i < liste_coups.size(); i ++){
                v = min(v, liste_coups[i].minmax(profondeur - 1, alpha, beta, !joueur, cible, coupsRestants-1));
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
    for (int i=0; i<taille; i++) {
        for (int j=0; j<taille; j++) {
            cout<<get(i,j).getcouleur()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
