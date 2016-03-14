#include "machine.h"

Machine::Machine(float coef1, float coef2, float coef3)
{
    coef_pos = coef1;
    coef_mob = coef2;
    coef_nb = coef3;
}

void Machine::setCoefPos(float coef) {
    coef_pos = coef;
}

float Machine::getCoefPos() {
    return coef_pos;
}

void Machine::setCoefMob(float coef) {
    coef_mob = coef;
}

float Machine::getCoefMob() {
    return coef_mob;
}

void Machine::setCoefNb(float coef) {
    coef_nb = coef;
}

float Machine::getCoefNb() {
    return coef_nb;
}

void Machine::setNewCoefs(float coef1, float coef2, float coef3) {
    coefPosList.push_back(coef_pos);
    coefMobList.push_back(coef_mob);
    coefNbList.push_back(coef_nb);

    coef_pos = coef1;
    coef_mob = coef2;
    coef_nb = coef3;
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
