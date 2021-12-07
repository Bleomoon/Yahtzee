#ifndef _LANCER_H_
#define _LANCER_H_

#include <string>
#include <vector>
#include "De.h"

class Lancer
{
    De* des;
public:
    Lancer(const int NB_DE);
    ~Lancer();
    Lancer& operator=(const Lancer& copy);
    void lance(int* indiceslances) const;
    De* get_des();
};
#endif