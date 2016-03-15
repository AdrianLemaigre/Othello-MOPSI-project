#include "genetique.h"

pair< vector<Machine>, vector<float> > selection(vector<Machine> echantillon_mere){
	vector<int> victoires;
	for(int k = 0; k < echantillon_fille.size(); k++){
		victoires.push_back(0);
	}
	for(int i = 0; i < echantillon_fille.size(); i++){
		for(int j = 0; j < echantillon_fille.size(); j ++){
			// Faire jouer les machines les unes contre les autres
			if(/* machine i gagne*/){
				victoires[i] += 1;
			}
			else{
				victoires[j] += 1;
			}
		}
	}
	int total = 0;
	for(int l = 0; l < echantillon_fille.size(); l++){
		total += victoires[l];
	}
	vector<int> proba;
	for(int m = 0; m < echantillon_fille.size(); m++){
		proba.push_back(victoires[m]/total);
	}
	pair< vector<Machine>, vector<float> > couples;
	first(couples) = echantillon_mere;
	second(couples) = proba;
	return couples;
}

vector<Machine> croisement(pair<vector<Machine>, vector<float> >){

}
// On crée les nouveaux coefficients

vector<Machine> mutation(vector<machine>){

}
// On ajoute de l'aléa dans le processus avec une probabilité donnée

vector<Machine> generation(vector<Machine>){

}
