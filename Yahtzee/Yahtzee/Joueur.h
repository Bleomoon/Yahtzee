#ifndef _JOUEUR_H_
#define _JOUEUR_H_


#include <iostream>
#include <string>
#include <vector>

#include "Figures/Figure.h"
#include "Figures/Brelan.h"
#include "Figures/Carre.h"
#include "Figures/Chance.h"
#include "Figures/Combinaison.h"
#include "Figures/Full.h"
#include "Figures/Grande_suite.h"
#include "Figures/Petite_suite.h"
#include "Figures/Yahtzee.h"
#include "Yahtzee_game.h"
#include "Lancer.h"
#include "De.h"

const int NB_SUPERIEURS = 6;
const int NB_INFERIEURS = 7;

class Joueur
{
    int totalScore;
    std::string nom;
    std::vector<Figure*> superieurs;
    std::vector<Figure*> inferieurs;
    Yahtzee_game* yahtzee_g;
public:
    Joueur(Yahtzee_game* jeu, std::string nom);
    Joueur(const Joueur& copy);
    ~Joueur();
    Joueur& operator=(const Joueur& copy);
    int get_total_score();
    void ajouter_superieurs(int* recap, int valeur);
    void ajouter_inferieurs(int* recap, int valeur);
    void tour_joueur(Lancer& l);
    void afficher_possibilite(std::vector<Figure*>& possibilite);
    std::string get_nom();
    void superieurs_restante(std::vector<int>* indexs);
    void inferieurs_restante(std::vector<int>* indexs);
    int abandonne(int* recap);
    int relancer_des(Lancer& l);
    int* get_recapitulatif(De* des);

private:
    int choix_correct(std::string selected, int max);
    int* des_relance(std::string des_r);
};

#endif