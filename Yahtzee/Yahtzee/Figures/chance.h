#ifndef _CHANCE_H_
#define _CHANCE_H_


#include "Figure.h"

class Chance: public Figure
{
public:
    Chance();
    bool set_figure(int* des);
    bool is_figure(int* des);
    int score_possible(int* recap);

    std::string get_name();

    friend std::ostream& operator<<(std::ostream& out, Chance& figure);
};

std::ostream& operator<<(std::ostream& out, const Chance& figure);
#endif