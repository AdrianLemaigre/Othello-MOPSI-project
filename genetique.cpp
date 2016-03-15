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

vector<Machine> mutation(vector<machine> generation_fille){
	vector<machine> generation_fille2 = generation_fille;
	for (int i = 0; i < generation_fille.size(); i++){
		for (int k = 0; k < 64;k ++){
			float mutantPos = ((float)rand()/(float)(RAND_MAX));
  			float mutantMob = ((float)rand()/(float)(RAND_MAX));
    		float mutantNb = ((float)rand()/(float)(RAND_MAX));
    		generation_fille2[i].setCoefPos(k, mutantPos);
    		generation_fille2[i].setCoefMob(k, mutantMob);
    		generation_fille2[i].setCoefNb(k, mutantNb);
		}
	}
	return generation_fille2;
}

vector<Machine> generation(vector<Machine> generation_mere){
	pair< vector<Machine>, vector<float> > creation = selection(vector<Machine> echantillon_mere);
	vector<Machine> generation_fille = croisement(creation);
	int prob = rand()%500;
	if (prob == 1){
		generation_fille = mutation(generation_fille);
	}
	return generation_fille;
}
