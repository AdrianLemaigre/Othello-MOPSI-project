#include "genetique.h"

int main(){
    init_table_point();
    srand(time(NULL));

    vector<Machine> m = initialise(10);

    for (int i=0; i<100; i++) {
        m = generation(m);
    }

    return 0;
}
