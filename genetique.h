#ifndef GENETIQUE_H
#define GENETIQUE_H

#include "jeu.h"
#include <cstdlib>

vector<Machine> initialise(int nb);

vector<pair<Machine, float> > selection(vector<Machine> echantillon_mere);
// On renvoie le classement (sous forme des probabilité)
// des machines de la génération

vector<Machine> croisement(vector<pair<Machine, float> > couples);
// On crée les nouveaux coefficients

vector<Machine> mutation(vector<Machine>);
// On ajoute de l'aléa dans le processus avec une probabilité donnée

vector<Machine> generation(vector<Machine>);

#endif
