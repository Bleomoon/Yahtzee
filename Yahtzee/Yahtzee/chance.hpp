#ifndef _CHANCE_H_
#define _CHANCE_H_


#include "Figure.hpp"

class Chance: public Figure
{
    int score;
public:
    Chance(bool abandonne, int score);
    ~Chance();
};
#endif