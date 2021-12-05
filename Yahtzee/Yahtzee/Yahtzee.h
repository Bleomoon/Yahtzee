#ifndef _YAHTZEE_H_
#define _YAHTZEE_H_


#include "Figure.hpp"

class Yahtzee : public Figure
{
    int score;
public:
    Yahtzee();
    ~Yahtzee();
    int get_score();
};
#endif