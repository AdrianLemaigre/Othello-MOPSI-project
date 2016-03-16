#include "genetique.h"

bool comparePair(const pair<Machine, float> c1, const pair<Machine, float> c2) {
    return c1.second > c2.second;
}

vector<Machine> initialise(int nb){
    vector<Machine> m;

    for (int i = 0; i < nb; i++) {
        m.push_back(Machine(i));
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

vector<pair<Machine, float> > randomMachines(vector<pair<Machine, float> > couples) {
    vector<pair <Machine, float> > parents;

    for (int i = 0; i < couples.size(); i++) {
        if (i%2 == 0) {
            parents.push_back(couples[i/2]);
        } else {
            float randomProba = (float)rand()/(float)(RAND_MAX);
            float sommeProba = couples[0].second;
            int k = 0;

            while (randomProba > sommeProba && k < couples.size() - 1) {
                sommeProba += couples[k+1].second;
                k++;
            }

            parents.push_back(couples[k]);
        }
    }

    cout<<endl;

    return parents;
}

vector<Machine> croisement(vector<pair<Machine, float> > couples) {
    vector<Machine> generation_fille;

    for (int i=0; i < couples.size(); i++) {
        Machine mere;
        Machine pere;
        float probaMere;
        float probaPere;

        if (i != couples.size()-1) {
            mere = couples[i].first;
            pere = couples[i+1].second;
            probaMere = couples[i].second;
            probaPere = couples[i+1].second;
        } else {
            mere = couples[i].first;
            pere = couples[0].second;
            probaMere = couples[i].second;
            probaPere = couples[0].second;
        }

        vector<float> coef1;
        vector<float> coef2;
        vector<float> coef3;

        for (int k = 0; k < mere.getSize(); k++) {
            coef1.push_back(mere.getCoefPos(k)*probaMere/(probaMere + probaPere) + pere.getCoefPos(k)*probaPere/(probaMere + probaPere));
            coef2.push_back(mere.getCoefMob(k)*probaMere/(probaMere + probaPere) + pere.getCoefMob(k)*probaPere/(probaMere + probaPere));
            coef3.push_back(mere.getCoefNb(k)*probaMere/(probaMere + probaPere) + pere.getCoefNb(k)*probaPere/(probaMere + probaPere));
        }

        generation_fille.push_back(Machine(coef1, coef2, coef3, i));
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
    afficheCouple(creation);
    vector<pair<Machine, float> > randomCreation = randomMachines(creation);
    afficheCouple(randomCreation);
    vector<Machine> generation_fille = croisement(randomCreation);
	int prob = rand()%500;
    if (prob == 0){
		generation_fille = mutation(generation_fille);
	}
	return generation_fille;
}

void afficheVec(vector<Machine> v) {
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].getName()<<" ";
    }
    cout<<endl;
}

void afficheCouple(vector<pair<Machine, float> > v) {
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].first.getName()<<" : "<<v[i].second<< " ";
    }
    cout<<endl;
}
