#include "machine.h"

Machine::Machine(float min, float max, int nbCoefs) {
    srand(time(NULL));


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

