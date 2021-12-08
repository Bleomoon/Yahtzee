#ifndef _BRELAN_H_
#define _BRELAN_H_


#include "Figure.h"

class Brelan: public Figure
{
public:
    Brelan();
    bool set_figure(int* recap);
    bool is_figure(int* recap);
    int score_possible(int* recap);

    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, const Brelan& figure);

#endif