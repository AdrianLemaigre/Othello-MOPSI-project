// Classes
// Classe Pion

class Pion
{
public:
  // Constructeurs
  Pion();
  Pion(int clr);

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
  void set(Pion p, int i, int j);
  Pion get(int k);
  void set(Pion p, int k);

  // Autres méthodes
  Grille ajout_pion(int i, int j, int couleur);
  int score(Grille g, bool joueur);
  // Grille Etape_de_jeu()
  // Fonction d'un coup joué
  // Grille algo_minmax();
  // Fonction globale qui renvoie la grille finale

private:
  int taille;
  Pion* table;
  int direction [4] = {1, -1, taille,-taille}
};

//Paramètres
// Taille du tableau
int taille_othello = 8;
// Table des points de la grille
int table_point [10][10];
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

