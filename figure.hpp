#include <iostream>

class figure
{
    int score;
public:
    figure();
    virtual ~figure();
    virtual int get_score();
};

int figure::get_score()
{
    return score;
}