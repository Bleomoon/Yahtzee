#include "Joueur.h"

//le joueur re�oit un nom et l'adresse du jeu pour jouer son tour au moment ou on l'appel et avoir ainsi acc�s au d�s
Joueur::Joueur(Yahtzee_game* jeu, std::string nom)
{
    // initialisation de joueur
    this->nom = nom;
    this->yahtzee_g = jeu;

    // reserve de la m�moire
    superieurs.reserve(NB_SUPERIEURS);
    inferieurs.reserve(NB_INFERIEURS);

    // initialisation de sup�rieure
    superieurs.push_back(new Combinaison<1>());
    superieurs.push_back(new Combinaison<2>());
    superieurs.push_back(new Combinaison<3>());
    superieurs.push_back(new Combinaison<4>());
    superieurs.push_back(new Combinaison<5>());
    superieurs.push_back(new Combinaison<6>());
    superieurs.shrink_to_fit(); // on enl�ve le surplus en m�moire

    // initialisation de inf�rieure
    inferieurs.push_back(new Brelan());
    inferieurs.push_back(new Petite_suite());
    inferieurs.push_back(new Grande_suite());
    inferieurs.push_back(new Full());
    inferieurs.push_back(new Carre());
    inferieurs.push_back(new Yathzee());
    inferieurs.push_back(new Chance());
    superieurs.shrink_to_fit(); // on enl�ve le surplus en m�moire
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
        std::cout << "Supprime toute les anciennes donn�es du joueur pour �vit� la fuite m�moire" << std::endl;
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
    // si le total a d�j� �t� calcul�
    if (totalScore != 0)
        return totalScore;

    // compter les points pour sup�rieur;
    for (auto it : superieurs) {
        totalScore += it->get_score();
    }

    // si le le total des combinaison est �gale a 63 le score passe 98
    if (totalScore == 63)
        totalScore == 98;

    // compter les points pour les combinaison sup�rieurs
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
        - s�lectionner une possibilit�
        - relancer certains d�s
        - ou abandonner une possibilit�
*/
void Joueur::tour_joueur(Lancer& l)
{
    std::cout << "D�but du tour " << this->nom << std::endl;
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
        std::cout << (all_possibilites.size() + 1) << ". Relancer les d�s" << std::endl;
        std::cout << (all_possibilites.size() + 2) << ". Abandonn� une possibilit�" << std::endl;
        // a nomF
        // v nomF
        // r pr�cisez les d�s
        while (choice == -1)
        {
            std::scanf("%s", &selected);
            choice = choix_correct(selected, all_possibilites.size() + 2);
        }
        if (choice <= 6) //combinaison sup�rieur
        {
            //ici on modifie en set_figure de la figure en question
            //ici je dois r�cap avant
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if(choice <= 13)//combinaison inf�rieur
        {
            //ici on modifie en set_figure de la figure en question
            this->ajouter_superieurs(all_possibilites.at(choice));
        }
        else if (choice <= 13)//Relancer les d�s
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

//affiche les possibilit�s en fonction des d�s
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

// V�rifie que le joueur ne rentre pas n'importe quoi dans ces choix, on veux un int entre 1 et max
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

int Joueur::abandonne()
{
    int choice = -1;
    std::string selected;

    std::cout << "Select what you want to drop:" << std::endl;
    std::vector<const Figure*> fig_restante = this->figure_restante();

    for (int i = 0; i < fig_restante.size(); i++)
    {
        std::cout << i << ". " << fig_restante.at(i) << std::endl;
    }
    std::cout << (fig_restante.size() + 1) << ". revenir en arri�re" << std::endl;

    while (choice == -1)
    {
        std::scanf("%s", &selected);
        choice = choix_correct(selected, (fig_restante.size() + 1));
    }
    if (choice == fig_restante.size() + 1)
        return -1;
    else
    {
        //drop the selected figure
        //ici on set_figure
    }
    return choice;
}

int Joueur::relancer_des(Lancer &l)
{
    int choice = -1, cpt_d = 0;
    bool relance = false;
    std::vector<int> des_r;
    std::string selected;

    std::cout << "S�lectionner quel d� pour voulez relancer : " << std::endl;
    for (int i = 0; i < 5 ; i++) //boucle sur les d�s pour les affich�s
    {
        std::cout << "D� " << i << " : " << l.get_des()[i].to_String() << std::endl;
    }
    std::cout << 6 << ". revenir en arri�re" << std::endl;

    //si un d�s d�ja valider :(
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
        //r�cup�re des int pour les d�s
        l.lance();//les d�s en question relanc�
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