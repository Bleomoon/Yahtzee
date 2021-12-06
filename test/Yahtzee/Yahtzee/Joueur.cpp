#include "Joueur.h"
#include "Figures/Brelan.h"
#include "Figures/carre.h"
#include "Figures/chance.h"
#include "Figures/Combinaison.h"
#include "Figures/Full.h"
#include "Figures/Grande_suite.h"
#include "Figures/Yathzee.h"
#include "Figures/Petite_suite.h"

//le joueur reçoit un nom et l'adresse du jeu pour jouer son tour au moment ou on l'appel et avoir ainsi accès au dés
Joueur::Joueur(Yahtzee_game* jeu, std::string nom)
{
    // initialisation de joueur
    this->nom = nom;
    this->yahtzee_g = jeu;
    
    // reserve de la mémoire
    superieurs.reserve(NB_SUPERIEURS);
    inferieurs.reserve(NB_INFERIEURS);
    
    // initialisation de supérieure
    superieurs.push_back(new Combinaison<1>());
    superieurs.push_back(new Combinaison<2>());
    superieurs.push_back(new Combinaison<3>());
    superieurs.push_back(new Combinaison<4>());
    superieurs.push_back(new Combinaison<5>());
    superieurs.push_back(new Combinaison<6>());
    superieurs.shrink_to_fit(); // on enlève le surplus en mémoire

    // initialisation de inférieure
    inferieurs.push_back(new Brelan());
    inferieurs.push_back(new Petite_suite());
    inferieurs.push_back(new Grande_suite());
    inferieurs.push_back(new Full());
    inferieurs.push_back(new Carre());
    inferieurs.push_back(new Yathzee());
    inferieurs.push_back(new Chance());
    superieurs.shrink_to_fit(); // on enlève le surplus en mémoire
}

Joueur::Joueur(const Joueur& copy)
{
    if(this != &copy)
    {
        // TODO
        this->inferieurs = copy.inferieurs;
        this->superieurs = copy.superieurs;
        this->nom = copy.nom;
        this->totalScore = copy.totalScore;
        this->yahtzee_g = copy.yahtzee_g;
    }
}

Joueur::~Joueur()
{
    // TODO 
    std::cout << "Deletion of the player" << std::endl;
    this->superieurs.clear();
    this->inferieurs.clear();
    delete this->yahtzee_g;
}

Joueur& Joueur::operator=(const Joueur& copy)
{
    if (this != &copy)
    {
        // TODO
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
    // si le total a déjà été calculé
    if (totalScore != 0)
        return totalScore;

    // compter les points pour supérieur;
    for (auto it : superieurs) {
        totalScore += it->get_score();
    }

    // si le le total des combinaison est égale a 63 le score passe 98
    if (totalScore == 63)
        totalScore == 98;

    // compter les points pour les combinaison supérieurs
    for (auto it : inferieurs) {
        totalScore += it->get_score();
    }

    return this->totalScore;
}

//ajout d'une figure de type combinaison donc les 6 ou 5 etc
void Joueur::ajouter_superieurs(int valeur_de)
{
}

//ajout d'une figure carre, brelan etc

void Joueur::ajouter_inferieurs(std::string nom)
{
}

/*Affiche les possibilite, propose de :
        - sélectionner une possibilité
        - relancer certains dés
        - ou abandonner une possibilité
*/
void Joueur::tour_joueur(Lancer& l)
{
    std::cout << "Start of turn for " << this->nom << std::endl;
    std::string selected;
    int choice = -1;
    bool garde = false;
    int cpt_tour = 0;
    int valD[5] = { 1, 2, 3, 4, 5 };
    int *des =  l.lance(valD) ;
    
    while (!garde || cpt_tour < 3)
    {
        std::vector<const Figure f*> all_possibilites = l.possibilite(this);
        afficher_possibilite(all_possibilites);
        std::cout << (all_possibilites.size() + 1) << ". Relancer les dés" << std::endl;
        std::cout << (all_possibilites.size() + 2) << ". Abandonné une possibilité" << std::endl;

        while (choice == -1)
        {
            std::scanf("%s", &selected);
            choice = is_correct_choice(selected, all_possibilites.size() + 2);
        }
        if (choice <= 6) //combinaison supérieur
        {
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if(choice <= 13)//combinaison inférieur
        {
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if (choice <= 13)//Relancer les dés
        {
            std::cout << "Select which dies you want to throw again:" << std::endl;
            
            for (int i = 0; i < l.size(); i++) //boucle sur les dés pour les afciéhs
            {
                
            }
            std::cout << (l.size() + 1) << ". revenir en arrière" << std::endl;

            if (choice == l.size() + 1)
                cpt_tour--;
            else
            {
                //récupère des int pour les dés
                l.lance()//les dés en question relancé
            }
            
        }
        else // abandonner une combinaison
        {
            std::cout << "Select what you want to drop:" << std::endl;
            std::vector<const Figure*> fig_restante = this->figure_restante();
            for (int i = 0; i < fig_restante.size(); i++)
            {
                std::cout << i << ". " << fig_restante.at(i) << std::endl;
            }
            std::cout << (fig_restante.size() + 1) << ". revenir en arrière" << std::endl;

            choice = -1;
            while (choice == -1)
            {
                std::scanf("%s", &selected);
                choice = is_correct_choice(selected, (fig_restante.size() + 1));
            }
            if(choice == fig_restante.size() + 1)
                cpt_tour--;
            else
            {
                //drop the selected figure
            }
        }
        cpt_tour++;
    }

    std::cout << "End of turn for " << this->nom << std::endl;
}

//affiche les possibilités en fonction des dés
void Joueur::afficher_possibilite(std::vector<Figure*>& possibilite)
{
    std::cout << "Possibilités supérieurs : " << std::endl;

    for ()


    std::cout << "Select what you want to keep:" << std::endl;
    for (int i = 0; i < possibilite.size(); i++)
    {
        std::cout << i << ". " << possibilite.at(i) << std::endl;
    }
}

std::string Joueur::get_nom()
{
    return this->nom;
}

// retourne les figure superierus encore disponible pour le joueur
std::vector<Figure*>& Joueur::superieurs_restante()
{
    //retourne les figure encore disponible pour le joueur
}

// retourne les figure inferieurs encore disponible pour le joueur
std::vector<Figure*>& Joueur::inferieurs_restante()
{
    return std::vector<const Figure*>();
}

// Vérifie que le joueur ne rentre pas n'importe quoi dans ces choix, on veux un int entre 1 et max
int Joueur::is_correct_choice(std::string selected, int max)
{
    int number = -1;
    try
    {
        number = std::stoi(selected);
    }
    catch (...)
    {
        std::cout << "Please enter a number !" << std::endl;
    }
    if (number < 0 && number > max + 1)
        std::cout << "Please enter a number between 1 and " << max << std::endl;
    return number;
}