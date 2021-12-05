#ifndef _PETITE_SUITE_H_
#define _PETITE_SUITE_H_


#include "Figure.h"

class Petite_suite : public Figure
{
public:
    Petite_suite(bool abandonne, int score);
    ~Petite_suite();
};
#endif