#include <iostream>

#include "figure.hpp"

class carre: public figure
{
    int score;
public:
    carre(int d1, int d2, int d3, int d4) { this->score = d1+d2+d3+d4; };
    ~carre();
    int get_score();
};