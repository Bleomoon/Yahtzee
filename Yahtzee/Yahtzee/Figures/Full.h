#ifndef _FULL_H_
#define _FULL_H_


#include "Figure.h"

class Full: public Figure
{
public:
    bool set_figure(int* recap);
    bool is_figure(int* recap);
    int score_possible(int* recap);


    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, const Full& figure);
#endif