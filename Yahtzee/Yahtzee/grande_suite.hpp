#include <iostream>

#include "figure.hpp"

class grande_suite: public Figure
{
    int score = 40;
public:
    grande_suite(bool abandonne, int score);
    ~grande_suite();
    int get_score();
};