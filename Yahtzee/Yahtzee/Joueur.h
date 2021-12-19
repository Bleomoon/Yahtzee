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
#include "Lancer.h"
#include "De.h"

const int NB_SUPERIEURS = 6;
const int NB_INFERIEURS = 7;
class Yahtzee_jeux;
int choix_correct(std::string selected, int max, int min);

class Joueur
{
    int totalScore;
    std::string nom;
    std::vector<Figure*> superieurs;
    std::vector<Figure*> inferieurs;
    Yahtzee_jeux* yahtzee_g;
public:
    Joueur(Yahtzee_jeux* jeu, std::string nom);
    Joueur(const Joueur& copy);
    ~Joueur();
    Joueur& operator=(const Joueur& copy);
    int avoir_total_score();
    void tour_joueur(Lancer& l);
    std::string avoir_nom();
    void afficher_possibilite(int* recap, int cpt_tour, std::vector<int> inferieurs_possible, std::vector<int> superieurs_restant);
    void ajouter_superieurs(int* recap, int valeur);
    void ajouter_inferieurs(int* recap, int valeur);
    void superieurs_restante(std::vector<int>* indexs); 
    void inferieurs_restante(std::vector<int>* indexs_possible, std::vector<int>* indexs_impossible, int* recap);
    int abandonne(int* recap, std::vector<int>* inferieurs_impossible);
    int relancer_des(Lancer& l);
    void avoir_recapitulatif(De** des, int* recap);
    int* des_relance(std::string des_r);
};

#endif