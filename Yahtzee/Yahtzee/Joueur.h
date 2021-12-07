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
    void ajouter_superieurs(int valeur_de);
    void ajouter_inferieurs(std::string nom);
    void tour_joueur(Lancer& l);
    void afficher_possibilite(std::vector<Figure*>& possibilite);
    std::string get_nom();
    std::vector<Figure*>& superieurs_restante();
    std::vector<Figure*>& inferieurs_restante();
    int abandonne();
    int relancer_des(Lancer& l);
private:
    int choix_correct(std::string selected, int max);
};

#endif