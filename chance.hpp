#include <iostream>

#include "figure.hpp"

class chance: public figure
{
    int score;
public:
    chance(int d1, int d2, int d3, int d4, int d5, int d6) { this->score = d1+d2+d3+d4+d5+d6; };
    ~chance();
    int get_score();
};