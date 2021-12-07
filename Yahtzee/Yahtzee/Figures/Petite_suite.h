#ifndef _PETITE_SUITE_H_
#define _PETITE_SUITE_H_

#include "Figure.h"

class Petite_suite : public Figure
{
public:
    bool set_figure(int* recap);
    bool is_figure(int* recap);

    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, const Petite_suite& figure);
#endif