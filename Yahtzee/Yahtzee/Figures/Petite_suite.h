#ifndef _PETITE_SUITE_H_
#define _PETITE_SUITE_H_

#include "Figure.h"

class Petite_suite : public Figure
{
public:
    bool valider_figure(int* recap);
    bool est_figure(int* recap);
    int score_possible(int* recap);

    std::string avoir_nom();
};

std::ostream& operator<<(std::ostream& out, const Petite_suite& figure);
#endif