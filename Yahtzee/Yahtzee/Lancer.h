#ifndef _LANCER_H_
#define _LANCER_H_

#include <string>
#include <vector>
#include "De.h"

class Lancer
{
    int nb_de;
    De** des;
public:
    Lancer(const int NB_DE);
    Lancer(const Lancer& copy);
    ~Lancer();
    Lancer& operator=(const Lancer& copy);
    void lance(int* indiceslances, int nb_indice);
    De** get_des();
};
#endif