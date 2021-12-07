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
void Joueur::ajouter_superieurs(int* recap, int valeur)
{
    this->superieurs.at(valeur)->set_figure(recap);
}

//ajout d'une figure carre, brelan etc
void Joueur::ajouter_inferieurs(int* recap, int valeur)
{
    this->inferieurs.at(valeur)->set_figure(recap);
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
        // a voir ici il fait un choix d'un num�ro mais quel choix le 1 pour le brelan? comment sait ton que c'est le brelan
        std::vector<const Figure f*> all_possibilites = l.possibilite(this);
        afficher_possibilite(all_possibilites);
        std::cout << (all_possibilites.size() + 1) << ". Relancer les d�s" << std::endl;
        std::cout << (all_possibilites.size() + 2) << ". Abandonn� une possibilit�" << std::endl;
        while (choice == -1)
        {
            std::scanf("%s", &selected);
            choice = choix_correct(selected, all_possibilites.size() + 2);
        }
        if (choice <= 6) //combinaison sup�rieur
        {
            this->ajouter_superieurs(this->get_recapitulatif(l.get_des()),choice);
        }
        else if(choice <= 13)//combinaison inf�rieur
        {
            this->ajouter_inferieurs(this->get_recapitulatif(l.get_des()), choice);
        }
        else if (choice <= 13)//Relancer les d�s
        {
            choice = this->relancer_des(l);
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
// a modifier
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

// remplis le vecteurs d'indexs pass� en param�re apres les indexs des figures  
// sup�rieurs non r�alis�
void Joueur::superieurs_restante(std::vector<int>* indexs)
{
    for (int index = 0; index < superieurs.size(); index++) {
        if (!superieurs.at(index)->is_assigner())
            indexs->push_back(index);
    }

    indexs->shrink_to_fit();

}

// remplis le vecteurs d'indexs pass� en param�re apres les indexs des figures  
// inf�rieurs non r�alis�
void Joueur::inferieurs_restante(std::vector<int>* indexs)
{
    for (int index = 0; index < inferieurs.size(); index++) {
        if (!inferieurs.at(index)->is_assigner())
            indexs->push_back(index);
    }

    indexs->shrink_to_fit();
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
    if (number < 1 && number > max)
        std::cout << "Please enter a number between 1 and " << max << std::endl;
    return number;
}

int Joueur::abandonne(int *recap)
{
    // afficher ce qu'il peut abandonner
    int choice = -1;
    std::string selected;

    std::cout << "Voici toutes les figures que vous pouvez abandonn� (stop pour revenir en arri�re):" << std::endl;
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

    // il n'y a plus combinaison inf�rieur a abandonn�
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
    int choice = -1;
    int* des_r = nullptr;
    std::string selected;

    std::cout << "S�lectionner quel d�s pour voulez relancer, format attendu (123456) : " << std::endl;
    for (int i = 1; i <= 6 ; i++) //boucle sur les d�s pour les affich�s
    {
        std::cout << "D� " << i << " : " << l.get_des()[i].to_String() << std::endl;
    }
    std::cout << 7 << ". revenir en arri�re" << std::endl;

    //si 7 alors sort sinon test le string en entier et boucle jusqu'a obtenir une bonne valeur
    do
    {
        try
        {
            int n = std::stoi(selected);
            if (n == 7)
            {
                return -1;
                break;
            }
        }
        catch (...)
        {

        }
        des_r = this->des_relance(selected);
        std::scanf("%s", &selected);
    } while (des_r == nullptr);

    if(des_r != nullptr)
        l.lance(des_r);
    return 0;
}

//fonction pour avoir un tableau de int avec tout les d�s et v�rifi� que leur formats est correct
int* Joueur::des_relance(std::string des_r)
{
    int relance[sizeof(des_r)];
    // pas de doublon, pas de d�s > 5 et < 1 et pas de lettres
    if (des_r.size() > 5)
    {
        std::cout << "Erreur dans la chaine envoy�, taille trop grande" << std::endl;
        return nullptr;
    }
    else
    {
        int number;
        for (int i = 0; i < des_r.size(); i++)
        {
            number = this->choix_correct(std::string(1, des_r[i]), 5);
            if (number == -1)
                return nullptr;
            else
                relance[i] = number;
        }

        //v�rifie les doublons
        for (int i = 0; i < des_r.size(); i++)
        {
            number = relance[i];
            for (int j = i; j < des_r.size(); j++)
            {
                if (number == relance[j])
                    return nullptr;
            }
        }
    }
    
    return relance;
}

int* Joueur::get_recapitulatif(De* des)
{
    // on fait le recapitulatif des valeurs obtenues
    int recap[6];
    for (int current : recap) {
        current = 0;
    }

    for (int index = 0; index < 6; index++) {
        recap[des[index].get_val() - 1] ++;
    }
    return recap;
}