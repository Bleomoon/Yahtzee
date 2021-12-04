#include <iostream>

class Figure
{
    const bool abandonne;
    const int score;
public:
    Figure(bool abandonne, int score);
    virtual ~Figure() = 0;
    virtual int get_score() = 0;
};
