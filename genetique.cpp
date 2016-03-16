#include "genetique.h"

bool comparePair(const pair<Machine, float> c1, const pair<Machine, float> c2) {
    return c1.second > c2.second;
}

vector<Machine> initialise(){

}

vector<pair<Machine, float> > selection(vector<Machine> echantillon_mere) {
	vector<int> victoires;
    int total = 0;

    for(int k = 0; k < echantillon_mere.size(); k++) {
		victoires.push_back(0);
	}
    for(int i = 0; i < echantillon_mere.size(); i++) {
        for(int j = 0; j < echantillon_mere.size(); j ++) {
			if(i != j){
                Jeu partie(echantillon_mere[i], echantillon_mere[j]);
                partie.vsMachine(true,64,0);
				// Verifier si  c'est la bonne machine qui gagne
				if(partie.gagne()){
                    cout<<"1 gagne"<<endl;
                    victoires[i]++;
				}
				else{
                    cout<<"2 gagne"<<endl;
                    victoires[j]++;
				}
                total++;
			}
		}
	}

    vector<pair<Machine, float> > couples;

    for (int i = 0; i < echantillon_mere.size(); i++) {
        couples.push_back(make_pair(echantillon_mere[i], victoires[i]/(double)total));
    }

    sort(couples.begin(), couples.end(), comparePair);

	return couples;
}

vector<Machine> croisement(vector<pair<Machine, float> >) {

}

vector<Machine> mutation(vector<Machine> generation_fille){
    vector<Machine> generation_fille2 = generation_fille;
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

vector<Machine> generation(vector<Machine> generation_mere) {
    vector<pair<Machine, float> > creation = selection(generation_mere);
	vector<Machine> generation_fille = croisement(creation);
	int prob = rand()%500;
	if (prob == 1){
		generation_fille = mutation(generation_fille);
	}
	return generation_fille;
}
