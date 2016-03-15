#ifndef GENETIQUE_H
#define GENETIQUE_H

#include "jeu.h"

pair< vector<Machine>, vector<float> > selection();
// On renvoie le classement (sous forme des probabilité)
// des machines de la génération

vector<Machine> croisement(pair<vector<Machine>, vector<float> >);
// On crée les nouveaux coefficients

vector<Machine> mutation(vector<machine>);
// On ajoute de l'aléa dans le processus avec une probabilité donnée

vector<Machine> generation(vector<Machine>);

#endif
