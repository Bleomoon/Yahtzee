#ifndef _CHANCE_H_
#define _CHANCE_H_


#include "Figure.h"

class Chance: public Figure
{
public:
    Chance();
    bool valider_figure(int* des);
    bool est_figure(int* des);
    int score_possible(int* recap);

    std::string avoir_nom();

    friend std::ostream& operator<<(std::ostream& out, Chance& figure);
};

std::ostream& operator<<(std::ostream& out, const Chance& figure);
#endif