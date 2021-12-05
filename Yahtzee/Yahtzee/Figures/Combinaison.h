#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_


#include "Figure.hpp"
#include "Valeur.h"

template<typename T, Valeur v, int rep>
class Combinaison : public Figure
{
public:
    Combinaison(bool abandonne, int score);
    ~Combinaison();
};

#endif