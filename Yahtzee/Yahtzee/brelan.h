#ifndef _BRELAN_H_
#define _BRELAN_H_


#include "Figure.hpp"

class Brelan: public Figure
{
public:
    Brelan(bool abandonne, int score);
    ~Brelan();
};

#endif