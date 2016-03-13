#include <vector>
#include <utility>

using namespace std;

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

  // Destructeur
  ~Grille();

  //Accesseurs et mutateurs
  void settaille(int t);
  int gettaille() const;
  Pion get(int i, int j);
  void set(Pion p, int i, int j);
  Pion get(int k);
  void set(Pion p, int k);

  // Autres méthodes
  bool test_placement(int i, int j, int couleur);
  Grille ajout_pion(int i, int j, int couleur);
  vector<Grille> coups_possibles(int couleur);
  int score(bool joueur);
  int minmax (int profondeur, int alpha, int beta, bool joueur, bool etat_maxmin);

  // Fonction globale qui renvoie la grille finale

private:
  int taille;
  Pion* table;
  int direction[4];
};

//Paramètres
// Taille du tableau
const int taille_othello = 8;

