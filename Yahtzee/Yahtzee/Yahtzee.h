#ifndef _YAHTZEE_H_
#define _YAHTZEE_H_


#include "Figure.hpp"

class Yahtzee : public Figure
{
public:
    Yahtzee(bool abandonne, int score);
    ~Yahtzee();
};
#endif