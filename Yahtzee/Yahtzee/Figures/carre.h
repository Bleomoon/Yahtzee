#ifndef _CARRE_H_
#define _CARRE_H_


#include "Figure.hpp"

class Carre: public Figure
{
public:
    Carre(bool abandonne, int score);
    ~Carre();
};
#endif