#ifndef _JOUEUR_H_
#define _JOUEUR_H_


#include <iostream>
#include <string>
#include <vector>

#include "Figure.hpp"
#include "Yahtzee_game.h"
#include "Lancer.h"
#include "Combinaison.h"

class Joueur
{
    int totalScore;
    std::vector<Combinaison> superieurs;
    std::vector<Figure> inferieurs;
    Yahtzee_game* yahtzee_g;
public:
    Joueur(Yahtzee_game* jeu);
    ~Joueur();
    int get_total_score();
    void ajouter_superieurs(Figure f);
    void ajouter_inferieurs(Figure f);
    void tour_joueur(Lancer& l);
    void afficher_possibilite(std::string possibilite);
}

#endif