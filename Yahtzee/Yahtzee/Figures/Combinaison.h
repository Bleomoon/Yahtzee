#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_

#include "Figure.h"
#include "../De.h"

template<typename T>
class Combinaison : public Figure
{
    De v;
public:
    Combinaison(bool abandonne, int score, T val) : Figure(abandonne, score), v(val) {};
    ~Combinaison(){};
};

#endif