#ifndef _CARRE_H_
#define _CARRE_H_


#include "Figure.h"

class Carre: public Figure
{
public:
    bool set_figure(int* recap);
    bool is_figure(int* recap);

    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, const Carre& figure);
#endif