#include "genetique.h"

int main(){
    init_table_point();
    srand(time(NULL));

    vector<Machine> m = initialise(10);
    ofstream myfile;
    myfile.open ("coefs.txt");
    m[0].ecritCoefs(myfile);

    while (true) {
        m = generation(m);
        Machine premiere = m[0];
        premiere.afficheCoefs();
        premiere.ecritCoefs(myfile);
    }

    myfile.close();

    return 0;
}
