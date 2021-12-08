#ifndef _LANCER_H_
#define _LANCER_H_

#include <string>
#include <vector>
#include "De.h"

class Lancer
{
    De** des;
    int indice_rand; //pour un random plus juste !!
public:
    Lancer(const int NB_DE);
    Lancer(const Lancer& copy);
    ~Lancer();
    Lancer& operator=(const Lancer& copy);
    void lance(int* indiceslances, int nb_de);
    De** get_des();
};
#endif