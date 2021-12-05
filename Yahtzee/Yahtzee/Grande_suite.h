#ifndef _GRANDE_SUITE_H_
#define _GRANDE_SUITE_H_


#include "Figure.hpp"

class Grande_suite: public Figure
{
    int score = 40;
public:
    Grande_suite(bool abandonne, int score);
    ~Grande_suite();
};
#endif