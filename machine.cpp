#include "machine.h"

Machine::Machine(float min, float max, int nbCoefs) {
    srand(time(NULL));

    float a = max - min;

    for (int i = 0; i<nbCoefs; i++) {
        float coef1 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        float coef2 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        float coef3 = ((float)rand()/(float)(RAND_MAX)) * a + min;
        addCoefs(coef1, coef2, coef3);
    }
}

Machine::Machine(std::vector<float> coef1, std::vector<float> coef2, std::vector<float> coef3)
{
    coefPosList = coef1;
    coefMobList = coef2;
    coefNbList = coef3;
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

float Machine::setCoefPos(int i, float coef){
    coefPosList[i] = coef;
}

float Machine::setCoefMob(int i, float coef){
    coefMobList[i] = coef;
}

float Machine::setCoefNb(int i, float coef){
    coefNbList[i] = coef;
}

