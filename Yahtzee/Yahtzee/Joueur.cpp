#include "Joueur.h"

Joueur::Joueur(Yahtzee_game* jeu)
{
    // a player is init
    this->yahtzee_g = jeu;
}

Joueur::~Joueur()
{
    std::cout << "Deletion of the player" << std::endl;
    for(int i = 0; i < this->superieurs.size(); i++)
    {
        delete this->superieurs[i];
    }
    for (int i = 0; i < this->inferieurs.size(); i++)
    {
        delete this->inferieurs[i];
    }
    delete this->yahtzee_g;
}

int Joueur::get_total_score()
{
    return this->totalScore;
}

void Joueur::ajouter_superieurs(Figure f)
{
    this->superieurs.push_back(f);
}

void Joueur::ajouter_inferieurs(Figure f)
{
    this->inferieurs.push_back(f);
}

void Joueur::tour_joueur(Lancer& l)
{
    //tour
}

void Joueur::afficher_possibilite(std::string possibilite)
{
    //print possibilité
}