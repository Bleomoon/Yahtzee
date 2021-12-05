#ifndef _YAHTZEE_GAME_H_
#define _YAHTZEE_GAME_H_

#include <iostream>

#include "Joueur.h"
#include "Lancer.h"

class Yahtzee_game
{
    const int nb_lancer;
    Joueur nb_joueurs[];
    int numero_out;
public:
    Yahtzee_game(int nb_joueurs, std::string nom_joueurs[]);
    ~Yahtzee_game();
    void jouer();
};
#endif