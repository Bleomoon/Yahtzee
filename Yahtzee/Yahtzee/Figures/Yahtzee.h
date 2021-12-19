#ifndef _YATHZEE_H_
#define _YATHZEE_H_


#include "Figure.h"

class Yahtzee : public Figure
{
public:
    bool valider_figure(int* recap);
    bool est_figure(int* recap);
    int score_possible(int* recap);

    std::string avoir_nom();
};

std::ostream& operator<<(std::ostream& out, const Yahtzee& figure);
#endif