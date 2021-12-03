#include <iostream>

#include "figure.hpp"

class yahtzee: public figure
{
    int score;
public:
    yahtzee() { this->score = 50; };
    ~yahtzee();
    int get_score();
}