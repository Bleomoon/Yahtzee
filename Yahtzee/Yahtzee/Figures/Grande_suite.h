#ifndef _GRANDE_SUITE_H_
#define _GRANDE_SUITE_H_


#include "Figure.h"

class Grande_suite: public Figure
{
public:
    bool set_figure(int* recap);
    bool is_figure(int* recap);
    int score_possible(int* recap);

    std::string get_name();
};

std::ostream& operator<<(std::ostream& out, const Grande_suite& figure);
#endif