#include <iostream>

class figure
{
    int score;
public:
    virtual figure() = 0;
    virtual ~figure() = 0;
    virtual int get_score() = 0;
};

int figure::get_score()
{
    return score;
}