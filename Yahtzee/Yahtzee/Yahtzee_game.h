#ifndef _YAHTZEE_GAME_H_
#define _YAHTZEE_GAME_H_

#include <iostream>

#include "Joueur.h"
#include "Lancer.h"

const int NB_DE = 5;

class Yahtzee_game
{
    int nb_lancer;
    Joueur** joueurs;
    int nb_joueur;
    int numero_tour;
    Lancer* lancer;
public:
    Yahtzee_game(int nb_joueurs, std::string nom_joueurs[], int nb_lancer_par_tours);
    Yahtzee_game(int nb_lancer_par_tours); // constructeur
    Yahtzee_game(const Yahtzee_game& copy); // constructeur par copy
    ~Yahtzee_game(); // desctructeur
    Yahtzee_game& operator=(const Yahtzee_game& copy); // 
    void jouer();
    int get_nb_lancer();
};
#endif