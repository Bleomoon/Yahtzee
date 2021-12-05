#ifndef _JOUEUR_H_
#define _JOUEUR_H_


#include <iostream>
#include <string>
#include <vector>

#include "Figures/Figure.h"
#include "Yahtzee_game.h"
#include "Lancer.h"
#include "Figures/Combinaison.h"
#include "De.h"

class Joueur
{
    int totalScore;
    std::string nom;
    std::vector<const Combinaison<De*>*> superieurs;
    std::vector<const Figure*> inferieurs;
    Yahtzee_game* yahtzee_g;
public:
    Joueur(Yahtzee_game* jeu, std::string nom);
    Joueur(const Joueur& copy);
    ~Joueur();
    Joueur& operator=(const Joueur& copy);
    int get_total_score();
    void ajouter_superieurs(const Combinaison<De*> *c);
    void ajouter_inferieurs(const Figure *f);
    void tour_joueur(Lancer& l);
    void afficher_possibilite(std::vector<std::string> possibilite);
    std::string get_nom();
    std::vector<const Figure*> figure_restante();
    
private:
    int is_correct_choice(std::string selected, int max);
};

#endif