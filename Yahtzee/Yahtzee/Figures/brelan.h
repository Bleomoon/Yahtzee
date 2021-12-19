#ifndef _BRELAN_H_
#define _BRELAN_H_


#include "Figure.h"

class Brelan: public Figure
{
public:
    Brelan();
    bool valider_figure(int* recap);
    bool est_figure(int* recap);
    int score_possible(int* recap);

    std::string avoir_nom();
};

std::ostream& operator<<(std::ostream& out, const Brelan& figure);

#endif