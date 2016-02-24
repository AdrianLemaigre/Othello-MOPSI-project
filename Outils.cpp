// Classes
// Classe Pion

class Pion
{
public:
  // Constructeurs
  Pion();
  Pion(int couleur);

  //Accesseurs et mutateurs
  void setcouleur(int y);
  int getcouleur() const;

  // Autres méthodes


private:
  int couleur;
};

// Classe de la grille
class Grille
{
public:
  // Constructeurs
  Grille();
  Grille(int t);

  //Accesseurs et mutateurs
  void settaille(int t);
  int gettaille() const;
  Pion get(int i, int j);

  // Autres méthodes
  Grille ajout_pion(int i, int j, int couleur);
  int score(Grille g, bool joueur);

private:
  int taille;
};

//Paramètres
// Taille du tableau
int taille_othello = 8;
// Table des points de la grille
int table_point [8][8];
void init_table_point(){
table_point[0][0] = 99;table_point[0][1] = -8;table_point[0][2] = 8;table_point[0][3] = 6;table_point[0][4] = 6;table_point[0][5] = 8;table_point[0][6] = -8;table_point[0][7] = 99;
table_point[1][0] = -8;table_point[1][1] = -24;table_point[1][2] = -4;table_point[1][3] = -3;table_point[1][4] = -3;table_point[1][5] = -4;table_point[1][6] = -24;table_point[1][7] = -8;
table_point[2][0] = 8;table_point[2][1] = -4;table_point[2][2] = 7;table_point[2][3] = 4;table_point[2][4] = 4;table_point[2][5] = 7;table_point[2][6] = -4;table_point[2][7] = 8;
table_point[3][0] = 6;table_point[3][1] = -3;table_point[3][2] = 4;table_point[3][3] = 0;table_point[3][4] = 0;table_point[3][5] = 4;table_point[3][6] = -3;table_point[3][7] = 6;
table_point[4][0] = 6;table_point[4][1] = -3;table_point[4][2] = 4;table_point[4][3] = 0;table_point[4][4] = 0;table_point[4][5] = 4;table_point[4][6] = -3;table_point[4][7] = 6;
table_point[5][0] = 8;table_point[5][1] = -4;table_point[5][2] = 7;table_point[5][3] = 4;table_point[5][4] = 4;table_point[5][5] = 7;table_point[5][6] = -4;table_point[5][7] = 8;
table_point[6][0] = -8;table_point[6][1] = -24;table_point[6][2] = -4;table_point[6][3] = -3;table_point[6][4] = -3;table_point[6][5] = -4;table_point[6][6] = -24;table_point[6][7] = -8;
table_point[7][0] = 99;table_point[7][1] = -8;table_point[7][2] = 8;table_point[7][3] = 6;table_point[7][4] = 6;table_point[7][5] = 8;table_point[7][6] = -8;table_point[7][7] = 99;
}

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
