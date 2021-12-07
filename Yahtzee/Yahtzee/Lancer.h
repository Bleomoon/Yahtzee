#ifndef _LANCER_H_
#define _LANCER_H_

#include <string>
#include <vector>
#include "De.h"
#include "Joueur.h"
#include "Yahtzee_game.h"

class Lancer
{
    De* des;
public:
    Lancer();
    ~Lancer();
    std::vector<Figure*>& possibilite(Joueur *j);
    void lance(int* indiceslances);
    De* get_des();
};
#endif