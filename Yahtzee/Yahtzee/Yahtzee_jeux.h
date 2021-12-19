#ifndef _YAHTZEE_GAME_H_
#define _YAHTZEE_GAME_H_

#include <iostream>
#include <vector>

#include "Lancer.h"

const int NB_DE = 5;

class Joueur;

class Yahtzee_jeux
{
    int nb_lancer;
    std::vector<Joueur*>* joueurs;
    int nb_joueur;
    int numero_tour;
    Lancer* lancer;
public:
    Yahtzee_jeux(int nb_lancer_par_tours); // constructeur
    Yahtzee_jeux(int nb_joueurs, std::string nom_joueurs[], int nb_lancer_par_tours);
    Yahtzee_jeux(const Yahtzee_jeux& copy); // constructeur par copy
    ~Yahtzee_jeux(); // desctructeur
    Yahtzee_jeux& operator=(const Yahtzee_jeux& copy); // 
    void jouer();
    int avoir_nb_lancer();
};
#endif