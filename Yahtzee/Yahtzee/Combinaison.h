#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_


#include "Figure.hpp"
#include "Valeur.h"

template<Valeur v, int rep>
class Combinaison : public Figure
{
    int score;
public:
    Combinaison(bool abandonne, int score);
    ~Combinaison();
};

#endif