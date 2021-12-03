#include <iostream>

#include "figure.hpp"

class grande_suite: public figure
{
    int score;
public:
    grande_suite() { this->score = 40; };
    ~grande_suite();
    int get_score();
};