#include "Joueur.h"

Joueur::Joueur(Yahtzee_game* jeu, std::string nom)
{
    // a player is init
    this->yahtzee_g = jeu;
    this->superieurs.reserve(6);
    this->inferieurs.reserve(7);
    this->nom = nom;
}

Joueur::Joueur(const Joueur& copy)
{
    if(this != &copy)
    {
        this->inferieurs = copy.inferieurs;
        this->superieurs = copy.superieurs;
        this->nom = copy.nom;
        this->totalScore = copy.totalScore;
        this->yahtzee_g = copy.yahtzee_g;
    }
}

Joueur::~Joueur()
{
    std::cout << "Deletion of the player" << std::endl;
    this->superieurs.clear();
    this->inferieurs.clear();
    delete this->yahtzee_g;
}

Joueur& Joueur::operator=(const Joueur& copy)
{
    if (this != &copy)
    {
        std::cout << "Supprime toute les anciennes données du joueur pour évité la fuite mémoire" << std::endl;
        this->inferieurs.clear();
        this->superieurs.clear();

        this->inferieurs = copy.inferieurs;
        this->superieurs = copy.superieurs;
        this->nom = copy.nom;
        this->totalScore = copy.totalScore;
        this->yahtzee_g = copy.yahtzee_g;
    }
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

std::string Joueur::get_nom()
{
    return this->nom;
}