#ifndef _FULL_H_
#define _FULL_H_


#include "Figure.h"

class Full: public Figure
{
public:
    bool valider_figure(int* recap);
    bool est_figure(int* recap);
    int score_possible(int* recap);


    std::string avoir_nom();
};

std::ostream& operator<<(std::ostream& out, const Full& figure);
#endif