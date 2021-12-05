#ifndef _FULL_H_
#define _FULL_H_


#include "Figure.hpp"

class Full: public Figure
{
public:
    Full(bool abandonne, int score);
    ~Full();
};
#endif