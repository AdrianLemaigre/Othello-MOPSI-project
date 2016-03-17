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
    std::cout << "Position:" << std::endl;
    for(int i = 0; i < coefPosList.size(); i++){
        std::cout << " coef " << i << " " << coefPosList[i] << "     ";
    }
    std::cout << std::endl;
    std::cout << "Mobilite:" << std::endl;
    for(int i = 0; i < coefMobList.size(); i++){
        std::cout << " coef " << i << " " << coefMobList[i] << "     ";
    }
    std::cout << std::endl;
    std::cout << "Nombre:" << std::endl;
    for(int i = 0; i < coefNbList.size(); i++){
        std::cout << " coef " << i << " " << coefNbList[i] << "     ";
    }
    std::cout << std::endl;
}

void Machine::ecritCoefs(std::ofstream &file) {
    file << "Position:" << std::endl;
    for(int i = 0; i < coefPosList.size(); i++){
        file << " coef " << i << " " << coefPosList[i] << "     ";
    }
    file << std::endl;
    file << "Mobilite:" << std::endl;
    for(int i = 0; i < coefMobList.size(); i++){
        file << " coef " << i << " " << coefMobList[i] << "     ";
    }
    file << std::endl;
    file << "Nombre:" << std::endl;
    for(int i = 0; i < coefNbList.size(); i++){
        file << " coef " << i << " " << coefNbList[i] << "     ";
    }
    file << std::endl;
}
