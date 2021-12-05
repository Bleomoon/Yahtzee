#ifndef _LANCER_H_
#define _LANCER_H_

#include <string>
#include <vector>
#include "De.h"
#include "Joueur.h"

class Lancer
{
    De des[5];
public:
    Lancer();
    ~Lancer();
    std::vector<std::string> possibilite(Joueur *j);
    int* lance(int* indiceslances);
};
#endif