#ifndef _CHANCE_H_
#define _CHANCE_H_


#include "Figure.h"

class Chance: public Figure
{
public:
    Chance(bool abandonne, int score);
    ~Chance();
};
#endif