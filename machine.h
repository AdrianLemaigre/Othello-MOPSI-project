#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>

class Machine
{
private:
    int name;
    std::vector<float> coefPosList;
    std::vector<float> coefMobList;
    std::vector<float> coefNbList;

public:
    Machine(int n = 0, float min = -1, float max = 1, int nbCoefs = 64);
    Machine(std::vector<float> coef1, std::vector<float> coef2, std::vector<float> coef3, int n = 0);

    int getName();
    int getSize();
    std::vector<float> getCoefPosList();
    std::vector<float> getCoefMobList();
    std::vector<float> getCoefNbList();
    void addCoefs(float coef1, float coef2, float coef3);
    float getCoefPos(int i);
    float getCoefMob(int i);
    float getCoefNb(int i);
    void setCoefPos(int i, float coef);
    void setCoefMob(int i, float coef);
    void setCoefNb(int i, float coef);

};

#endif
