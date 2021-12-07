#include "Joueur.h"

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

//a refaire
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

//a refaire
Joueur::~Joueur()
{
    std::cout << "Deletion of the player" << std::endl;
    this->superieurs.clear();
    this->inferieurs.clear();
    delete this->yahtzee_g;
}

// a refaire aussi
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
void Joueur::ajouter_superieurs(int* valeur_de)
{
    this->superieurs.at(valeur_de)->set_figure();
}

//ajout d'une figure carre, brelan etc
void Joueur::ajouter_inferieurs(std::string nom)
{
    this->inferieurs.push_back(f);
}

/*Affiche les possibilite, propose de :
        - sélectionner une possibilité
        - relancer certains dés
        - ou abandonner une possibilité
*/
void Joueur::tour_joueur(Lancer& l)
{
    std::cout << "Début du tour " << this->nom << std::endl;
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
        // a nomF
        // v nomF
        // r précisez les dés
        while (choice == -1)
        {
            std::scanf("%s", &selected);
            choice = choix_correct(selected, all_possibilites.size() + 2);
        }
        if (choice <= 6) //combinaison supérieur
        {
            //ici on modifie en set_figure de la figure en question
            //ici je dois récap avant
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if(choice <= 13)//combinaison inférieur
        {
            //ici on modifie en set_figure de la figure en question
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if (choice <= 13)//Relancer les dés
        {
            choice = this->relancer_des();
            if (choice == -1)
                cpt_tour--;
        }
        else // abandonner une combinaison
        {
            choice = this->abandonne();
            if (choice == -1)
                cpt_tour--;
        }
        cpt_tour++;
    }

    std::cout << "End of turn for " << this->nom << std::endl;
}

//affiche les possibilités en fonction des dés
void Joueur::afficher_possibilite(std::vector<Figure*>& possibilite)
{
    std::cout << "Selectionnez ce que vous voulez valider : " << std::endl;
    for (int i = 0; i < possibilite.size(); i++)
    {
        std::cout << i << ". " << possibilite.at(i) << std::endl;
    }
}

std::string Joueur::get_nom()
{
    return this->nom;
}

// remplis le vecteurs d'indexs passé en paramère apres les indexs des figures  
// supérieurs non réalisé
void Joueur::superieurs_restante(std::vector<int>* indexs)
{
    for (int index = 0; index < superieurs.size(); index++) {
        if (!superieurs.at(index)->is_assigner())
            indexs->push_back(index);
    }

    indexs->shrink_to_fit();

}

// remplis le vecteurs d'indexs passé en paramère apres les indexs des figures  
// inférieurs non réalisé
void Joueur::inferieurs_restante(std::vector<int>* indexs)
{
    for (int index = 0; index < inferieurs.size(); index++) {
        if (!inferieurs.at(index)->is_assigner())
            indexs->push_back(index);
    }

    indexs->shrink_to_fit();
}

// Vérifie que le joueur ne rentre pas n'importe quoi dans ces choix, on veux un int entre 1 et max
int Joueur::choix_correct(std::string selected, int max)
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

int Joueur::abandonne(int *recap)
{
    // afficher ce qu'il peut abandonner
    int choice = -1;
    std::string selected;

    std::cout << "Voici toutes les figures que vous pouvez abandonné (stop pour revenir en arrière):" << std::endl;
    std::vector<int> indexAbandonner;
    indexAbandonner.reserve(7);
    for (int index = 0; index < inferieurs.size(); index++) {
        Figure* current = inferieurs.at(index);
        if (!current->is_figure(recap)) {
            indexAbandonner.push_back(index);
            std::cout << index << ": " << current->get_name() << " ";
        }
    }
    indexAbandonner.shrink_to_fit();

    // il n'y a plus combinaison inférieur a abandonné
    if (indexAbandonner.size() == 0) {
        std::cout << "Vous ne pouvez plus abandonner de combinaison" << std::endl;
        return choice;
    }

    while (choice == -1)
    {
        std::scanf("%s", &selected);
        if (std::strcmp(selected.c_str(), "stop"))
            return -1;
        choice = choix_correct(selected, indexAbandonner.size());
    }

    return indexAbandonner.at(choice);
}

int Joueur::relancer_des(Lancer &l)
{
    int choice = -1, cpt_d = 0;
    bool relance = false;
    std::vector<int> des_r;
    std::string selected;

    std::cout << "Sélectionner quel dé pour voulez relancer : " << std::endl;
    for (int i = 0; i < 5 ; i++) //boucle sur les dés pour les affichés
    {
        std::cout << "Dé " << i << " : " << l.get_des()[i].to_String() << std::endl;
    }
    std::cout << 6 << ". revenir en arrière" << std::endl;

    //si un dés déja valider :(
    while (relance == false && cpt_d < 5)
    {
        while (choice == -1)
        {
            std::scanf("%s", &selected);
            choice = choix_correct(selected, (sizeof(l.get_des()) + 1));
        }
        des_r.push_back(choice);
        cpt_d++;
    }

    if (choice == 6)
        return -1;
    else
    {
        int all_d[des_r]
        //récupère des int pour les dés
        l.lance();//les dés en question relancé
    }
    return choice;
}

int* get_recapitulatif()
{
    // on fait le recapitulatif des valeurs obtenues
    int recap[6];
    for (int current : recap) {
        current = 0;
    }

    for (int index = 0; index < 6; index++) {
        recap[des[index].get_val() - 1] ++;
    }
}