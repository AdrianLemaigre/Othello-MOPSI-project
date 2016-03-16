#include "machine.h"

Machine::Machine(int n, float min, float max, int nbCoefs) {
    name = n;
    float a = max - min;

    for (int i = 0; i<nbCoefs; i++) {
        float coef1 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        float coef2 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        float coef3 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        addCoefs(coef1, coef2, coef3);
    }
}

Machine::Machine(std::vector<float> coef1, std::vector<float> coef2, std::vector<float> coef3, int n)
{
    name = n;
    coefPosList = coef1;
    coefMobList = coef2;
    coefNbList = coef3;
}

int Machine::getName() {
    return name;
}

int Machine::getSize() {
    return coefPosList.size();
}

std::vector<float> Machine::getCoefPosList() {
    return coefPosList;
}

std::vector<float> Machine::getCoefMobList() {
    return coefMobList;
}

std::vector<float> Machine::getCoefNbList() {
    return coefNbList;
}

void Machine::addCoefs(float coef1, float coef2, float coef3) {
    coefPosList.push_back(coef1);
    coefMobList.push_back(coef2);
    coefNbList.push_back(coef3);
}

float Machine::getCoefPos(int i) {
    return coefPosList[i];
}

float Machine::getCoefMob(int i) {
    return coefMobList[i];
}


float Machine::getCoefNb(int i) {
    return coefNbList[i];
}

void Machine::setCoefPos(int i, float coef){
    coefPosList[i] = coef;
}

void Machine::setCoefMob(int i, float coef){
    coefMobList[i] = coef;
}

void Machine::setCoefNb(int i, float coef){
    coefNbList[i] = coef;
}

void Machine::afficheCoefs(){
    cout << "Position:" << endl;
    for(int i = 0; i < coefPosList.size(); i++){
     cout << " coef " << i << " " << coefPosList[i] << "     ";
    }
    cout << endl;
    cout << "Mobilite:" << endl;
    for(int i = 0; i < coefMobList.size(); i++){
        cout << " coef " << i << " " << coefMobList[i] << "     ";
    }
    cout << endl;
    cout << "Nombre:" << endl;
    for(int i = 0; i < coefNbList.size(); i++){
        cout << " coef " << i << " " << coefNbList[i] << "     ";
    }
    cout << endl;
}
