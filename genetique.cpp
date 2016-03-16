#include "genetique.h"

bool comparePair(const pair<Machine, float> c1, const pair<Machine, float> c2) {
    return c1.second > c2.second;
}

vector<Machine> initialise(int nb){
    vector<Machine> m;

    for (int i = 0; i < nb; i++) {
        m.push_back(Machine());
    }

    return m;
}

vector<pair<Machine, float> > selection(vector<Machine> echantillon_mere) {
	vector<int> victoires;
    int total = 0;

    cout<<"Selection : 0%"<<flush;

    for(int k = 0; k < echantillon_mere.size(); k++) {
		victoires.push_back(0);
	}
    for(int i = 0; i < echantillon_mere.size(); i++) {
        for(int j = 0; j < echantillon_mere.size(); j ++) {
			if(i != j){
                Jeu partie(echantillon_mere[i], echantillon_mere[j]);
                cout<<"\rSelection : "<<((i*10+j)*100)/(echantillon_mere.size()*echantillon_mere.size())<<"%"<<flush;
                partie.vsMachine(true,64,0);
				// Verifier si  c'est la bonne machine qui gagne
				if(partie.gagne()){
                    victoires[i]++;
				}
				else{
                    victoires[j]++;
				}
                total++;
			}
		}
	}

    cout<<"\rSelection : 100%"<<endl;

    vector<pair<Machine, float> > couples;

    for (int i = 0; i < echantillon_mere.size(); i++) {
        couples.push_back(make_pair(echantillon_mere[i], victoires[i]/(double)total));
    }

    sort(couples.begin(), couples.end(), comparePair);

	return couples;
}

vector<Machine> croisement(vector<pair<Machine, float> > couples) {
    vector<Machine> generation_fille;

    for (int i=0; i < couples.size(); i++) {
        Machine mere;
        Machine pere;
        float probaMere;
        float probaPere;

        if (i != couples.size()-1) {
            Machine mere = couples[i].first;
            Machine pere = couples[i+1].second;
            float probaMere = couples[i].second;
            float probaPere = couples[i+1].second;
        } else {
            Machine mere = couples[i].first;
            Machine pere = couples[0].second;
            float probaMere = couples[i].second;
            float probaPere = couples[0].second;
        }

        vector<float> coef1;
        vector<float> coef2;
        vector<float> coef3;

        for (int k = 0; k < mere.getSize(); k++) {
            coef1.push_back(mere.getCoefPos(k)*probaMere/(probaMere + probaPere) + pere.getCoefPos(k)*probaPere/(probaMere + probaPere));
            coef2.push_back(mere.getCoefMob(k)*probaMere/(probaMere + probaPere) + pere.getCoefMob(k)*probaPere/(probaMere + probaPere));
            coef3.push_back(mere.getCoefNb(k)*probaMere/(probaMere + probaPere) + pere.getCoefNb(k)*probaPere/(probaMere + probaPere));
        }

        generation_fille.push_back(Machine(coef1, coef2, coef3));
    }

    return generation_fille;
}

vector<Machine> mutation(vector<Machine> generation_fille){
    vector<Machine> generation_fille2 = generation_fille;
	for (int i = 0; i < generation_fille.size(); i++){
        int k = rand()%generation_fille[i].getSize();

        float mutantPos = ((float)rand()/(float)(RAND_MAX));
        float mutantMob = ((float)rand()/(float)(RAND_MAX));
        float mutantNb = ((float)rand()/(float)(RAND_MAX));
        generation_fille2[i].setCoefPos(k, mutantPos);
        generation_fille2[i].setCoefMob(k, mutantMob);
        generation_fille2[i].setCoefNb(k, mutantNb);
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
