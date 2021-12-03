#include <iostream>

#include "figure.hpp"

class petite_suite: public figure
{
    int score;
public:
    petite_suite() { this->score = 30; };
    ~petite_suite();
    int get_score();
}