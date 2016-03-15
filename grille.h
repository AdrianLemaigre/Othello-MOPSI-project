#ifndef CLASSE_H
#define CLASSE_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "strategie.h"
#include "pion.h"

using namespace std;

//Paramètres
// Taille du tableau
const int taille_othello = 8;

class Grille
{
public:
    // Constructeurs
    Grille(int t = taille_othello);
    Grille(const Grille& g);

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
    int score(bool joueur, float coef_pos, float coef_mob, float coef_nb);
    int score_pos(bool joueur);
    int score_mob(bool joueur);
    int score_nb(bool joueur);
    int minmax (int profondeur, int alpha, int beta, bool joueur, bool cible, int coupsRestants,float coef_pos, float coef_mob, float coef_nb);
    void affiche();

private:
    int taille;
    Pion* table;
    int direction[8];
};

#endif
