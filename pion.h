#ifndef PION_H
#define PION_H


class Pion
{
public:
    // Constructeurs
    Pion();
    Pion(int clr);

    //Accesseurs et mutateurs
    void setcouleur(int y);
    int getcouleur() const;

    // Autres méthodes


private:
    int couleur;
};

#endif // PION_H
