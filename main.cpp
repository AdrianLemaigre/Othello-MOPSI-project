#include "genetique.h"

int main(){
    init_table_point();
    srand(time(NULL));

    vector<Machine> m;

    for (int i = 0; i < 10; i++) {
        m.push_back(Machine());
    }

    vector<pair<Machine, float> > p = selection(m);

    for (int i=0; i<p.size(); i++) {
        cout<<"Proba : "<<p[i].second<<endl;
    }

    return 0;
}
