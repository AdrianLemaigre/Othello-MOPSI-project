#include "genetique.h"

int main(){
    init_table_point();
    srand(time(NULL));

    vector<Machine> m = initialise(10);
    vector<Machine> m2 = generation(m);

    return 0;
}
