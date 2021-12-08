#include "Joueur.h"
#include "Yahtzee_game.h"

//le joueur re�oit un nom et l'adresse du jeu pour jouer son tour au moment ou on l'appel et avoir ainsi acc�s au d�s
Joueur::Joueur(Yahtzee_game* jeu, std::string nom) : nom(nom), yahtzee_g(jeu), totalScore(0)
{

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
    inferieurs.push_back(new Yahtzee());
    inferieurs.push_back(new Chance());
    superieurs.shrink_to_fit(); // on enl�ve le surplus en m�moire
}

Joueur::Joueur(const Joueur& copy)
{
    if(this != &copy)
    {
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

Joueur& Joueur::operator=(const Joueur& copy)
{
    if (this != &copy)
    {
        this->inferieurs = copy.inferieurs;
        this->superieurs = copy.superieurs;
        this->nom = copy.nom;
        this->totalScore = copy.totalScore;
        this->yahtzee_g = copy.yahtzee_g;
    }
    return *this;
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
        totalScore = 98;

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
    std::cout << "Debut du tour de " << this->nom << std::endl;
    std::string selected;
    int choice = -1, cpt_tour = 0;
    std::vector<int> inferieurs_possible, inferieurs_impossible, superieurs_restant;
    int des[5] = { 1, 2, 3, 4, 5 };
    l.lance(des, NB_DE);
    int* recap = this->get_recapitulatif(l.get_des());
    bool garde = false;

  
    while (!garde && cpt_tour < 3)
    {
        // affichage des des 
        De** des = l.get_des();
        for (unsigned int i = 0; i < 5; i++)
            std::cout << des[i]->get_val() << " ";

        std::cout << std::endl;

        afficher_possibilite(recap, cpt_tour, inferieurs_possible, superieurs_restant);
        
        while (choice == -1)
        {
            std::cin >> selected;
            choice = choix_correct(selected, inferieurs_possible.size() + superieurs_restant.size() + 2);
        }
        if (choice <= 6) //combinaison sup�rieur
        {
            this->ajouter_superieurs(recap, superieurs_restant.at(choice)-1);// TODO changer il faut regarde la valeur corespondante dans le tableau d'index
            garde = true;
        }
        else if(choice <= 13)//combinaison inf�rieur (-6 pour les inferieurs en moins)
        {
            this->ajouter_inferieurs(recap, inferieurs_possible.at(choice) -7); // TODO changer il faut regarde la valeur corespondante dans le tableau d'index
            garde = true;
        }// changer pas vraiment choice a 15 ca depend de la taille 
        else if (choice == (inferieurs_possible.size() + superieurs_restant.size() + 1) && cpt_tour < 2)//Relancer les d�s si il peux encore les relancés max de 2
        {
            choice = this->relancer_des(l);
        }
        else // abandonner une combinaison
        {
            choice = this->abandonne(recap);
            garde = true;
        }
        if (choice == -1)
        {
            cpt_tour--;
            garde = false;
        }
        cpt_tour++;
    }

    std::cout << "Fin du tour pour " << this->nom << "\n" << std::endl;
}

//affiche les possibilit�s en fonction des d�s
void Joueur::afficher_possibilite(int* recap, int cpt_tour, std::vector<int> inferieurs_possible, std::vector<int> superieurs_restant)
{
    //on crée un vector de int,int pour référencé les positions des figures, on affiche 1.deux 2.trois mais on stocke [(1,2), (2,3)]
    int val = 1;

    std::cout << "Selectionnez ce que vous voulez valider : " << std::endl;
    //boucle sur les indexs_inferieurs pour l'affichage
    for (int i = 0; i < superieurs_restant.size(); i++)
    {
        std::cout << val << ". " << this->superieurs.at(superieurs_restant.at(i))->get_name() << std::endl;
        val++;
    }
    

    //boucle sur les indexs_superieurs pour essayer de set_figure des cpy avec les dés existant
    //si le joueur décide de faire un indexs superieur en exemple de 6 alors qu'il n'a aucun dés de 6 ça met 0 dedans
    for (int i = 0; i < inferieurs_possible.size(); i++)
    {
        std::cout << val << ". " << this->inferieurs.at(inferieurs_possible.at(i))->get_name() << std::endl;
        val++;
    }
    
    std::cout << (val + 2) << ". Abandonn� une possibilit�" << std::endl;
    if (cpt_tour < 2)
        std::cout << (val + 1) << ". Relancer les des" << std::endl;
}

std::string Joueur::get_nom()
{
    return this->nom;
}

// remplis le vecteurs d'indexs pass� en param�re apres les indexs des figures  
// sup�rieurs non r�alis�
void Joueur::superieurs_restante(std::vector<int>* indexs)
{
    for (unsigned int index = 0; index < superieurs.size(); index++) {
        if (!superieurs.at(index)->is_assigner())
            indexs->push_back(index);
    }

    indexs->shrink_to_fit();

}

// remplis le vecteurs d'indexs pass� en param�re apres les indexs des figures  
// inf�rieurs non r�alis�
void Joueur::inferieurs_restante(std::vector<int>* indexs, int* recap)
{
    for (unsigned int index = 0; index < inferieurs.size(); index++) {
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
    for (unsigned int index = 0; index < inferieurs.size(); index++) {
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
        std::cin >> selected;
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
        std::cout << "D� " << i << " : " << l.get_des()[i]->to_String() << std::endl;
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
            // TODO
        }
        des_r = this->des_relance(selected);
        std::cin >> selected;
    } while (des_r == nullptr);

    if(des_r != nullptr)
        l.lance(des_r, std::strlen(selected.c_str()));
    return 0;
}

//fonction pour avoir un tableau de int avec tout les d�s et v�rifi� que leur formats est correct
int* Joueur::des_relance(std::string des_r)
{
    int* relance = new int[std::strlen(des_r.c_str())]; // voila de la bonne allocation dynamique
    // pas de doublon, pas de d�s > 5 et < 1 et pas de lettres
    if (des_r.size() > 5)
    {
        std::cout << "Erreur dans la chaine envoy�, taille trop grande" << std::endl;
        return nullptr;
    }
    else
    {
        int number;
        for (unsigned int i = 0; i < des_r.size(); i++)
        {
            number = this->choix_correct(std::string(1, des_r[i]), 5);
            if (number == -1)
                return nullptr;
            else
                relance[i] = number;
        }

        //v�rifie les doublons
        for (unsigned int i = 0; i < des_r.size(); i++)
        {
            number = relance[i];
            for (unsigned int j = i; j < des_r.size(); j++)
            {
                if (number == relance[j])
                    return nullptr;
            }
        }
    }
    
    return relance;
}

int* Joueur::get_recapitulatif(De** des)
{
    // on fait le recapitulatif des valeurs obtenues
    int recap[6];
    for (unsigned int index = 0; index < 5; index++) {
        recap[index] = 0;
    }

    for (unsigned int index = 0; index < 5; index++) {
        recap[(des[index]->get_val() - 1)] ++;
    }
    return recap;
}