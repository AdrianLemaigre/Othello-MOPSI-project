#ifndef MACHINE_H
#define MACHINE_H

#include <tuple>
#include <vector>

class Machine
{
private:
    float coef_pos;
    float coef_mob;
    float coef_nb;
    std::vector<float> coefPosList;
    std::vector<float> coefMobList;
    std::vector<float> coefNbList;

public:
    Machine(float coef1 = 1, float coef2 = 1, float coef3 = 1);

    void setCoefPos(float coef);
    float getCoefPos();
    void setCoefMob(float coef);
    float getCoefMob();
    void setCoefNb(float coef);
    float getCoefNb();

    void setNewCoefs(float coef1, float coef2, float coef3);
    int getSize();
    std::vector<float> getCoefPosList();
    std::vector<float> getCoefMobList();
    std::vector<float> getCoefNbList();

};

#endif // MACHINE_H
