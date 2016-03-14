#include "pion.h"

Pion::Pion(){
    couleur = -1;
}

Pion::Pion(int clr){
    couleur = clr;
}

void Pion::setcouleur(int y){
    couleur = y;
}

int Pion::getcouleur() const{
    return couleur;
}
