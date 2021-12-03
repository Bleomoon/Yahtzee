#include <iostream>

#include "figure.hpp"

class brelan: public figure
{
    int score;
public:
    brelan(int d1, int d2, int d3) { this->score = d1+d2+d3; };
    ~brelan();
    int get_score();
};