#include <iostream>

#include "figure.hpp"

class Yahtzee: public Figure
{
    int score;
public:
    Yahtzee();
    ~Yahtzee();
    int get_score();
}