#ifndef _YATHZEE_H_
#define _YATHZEE_H_


#include "Figure.h"

class Yahtzee : public Figure
{
public:
    bool set_figure(int* recap);
    bool is_figure(int* recap);

    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, Yahtzee& figure);
#endif