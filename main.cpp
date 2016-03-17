#include "genetique.h"

void afficheConsole(Grille G){
    cout <<"Partie d'Othello" << endl;
    for(i = 1; i < 9; i++)
    {
        cout <<"*****************************************"<< endl;
        cout <<"*   *   *   *   *   *   *   *   *   *   *" << endl;
        cout << "* "
        for(j = 1; j <9; j++){
            if (G.table[taille*i + j] == 0){
             cout <<"B *";
            }
            elseif(G.table[taille*i + j] == 0){
                cout <<"W *";
            }
            else{
                cout << "   *";
            }
        }
        cout << endl;
        cout <<"*   *   *   *   *   *   *   *   *   *   *" << endl;
    }
    cout <<"*****************************************" << endl;
}

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
