#ifndef _YAHTZEE_GAME_H_
#define _YAHTZEE_GAME_H_

#include <iostream>

#include "Joueur.h"
#include "Lancer.h"

class Yahtzee_game
{
    const int nb_lancer;
    Joueur** joueurs;
    int nb_joueur;
    int numero_tour;
    Lancer* lancer;
public:
    Yahtzee_game(int nb_joueurs, std::string nom_joueurs[], int nb_lancer_par_tours);
    Yahtzee_game(int nb_lancer_par_tours);
    ~Yahtzee_game();
    void jouer();
};
#endif