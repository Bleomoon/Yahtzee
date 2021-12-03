#include <iostream>

#include "figure.hpp"

class full: public figure
{
    int score;
public:
    full() { this->score = 25; };
    ~full();
    int get_score();
};