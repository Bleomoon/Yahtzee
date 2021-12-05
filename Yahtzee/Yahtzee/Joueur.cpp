#include "Joueur.h"

Joueur::Joueur(Yahtzee_game* jeu, std::string nom)
{
    // a player is init
    this->yahtzee_g = jeu;
    this->superieurs.reserve(6);
    this->inferieurs.reserve(7);
    this->nom = nom;
}

Joueur::~Joueur()
{
    std::cout << "Deletion of the player" << std::endl;
    this->superieurs.clear();
    this->inferieurs.clear();
    delete this->yahtzee_g;
}

int Joueur::get_total_score()
{
    return this->totalScore;
}

void Joueur::ajouter_superieurs(const Combinaison<De*> *c)
{
    this->superieurs.push_back(c);
}

void Joueur::ajouter_inferieurs(const Figure *f)
{
    this->inferieurs.push_back(f);
}

void Joueur::tour_joueur(Lancer& l)
{
    std::cout << "Start of turn for " << this->nom << std::endl;
    
    std::cout << "End of turn for " << this->nom << std::endl;
}

void Joueur::afficher_possibilite(std::string possibilite[])
{
    std::cout << "Select what you want to keep:" << std::endl;
    for (int i = 0; i < sizeof(possibilite); i++)
    {
        std::cout << possibilite[i] << std::endl;
    }
}