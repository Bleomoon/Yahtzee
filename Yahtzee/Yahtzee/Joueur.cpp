#include "Joueur.h"
#include "Yahtzee_jeux.h"

//le joueur re�oit un nom et l'adresse du jeu pour jouer son tour au moment ou on l'appel et avoir ainsi acc�s au d�s
Joueur::Joueur(Yahtzee_jeux* jeu, std::string nom) : nom(nom), yahtzee_g(jeu), totalScore(0)
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
    inferieurs.push_back(new Chance());
    inferieurs.push_back(new Brelan());
    inferieurs.push_back(new Petite_suite());
    inferieurs.push_back(new Grande_suite());
    inferieurs.push_back(new Full());
    inferieurs.push_back(new Carre());
    inferieurs.push_back(new Yahtzee());
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
    this->superieurs.clear();
    this->inferieurs.clear();
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

int Joueur::avoir_total_score()
{
    // si le total a d�j� �t� calcul�
    if (totalScore != 0)
        return totalScore;

    // compter les points pour sup�rieur;
    for (auto it : superieurs) {
        totalScore += it->avoir_score();
    }

    // si le le total des combinaison est �gale a 63 le score passe 98
    if (totalScore == 63)
        totalScore = 98;

    // compter les points pour les combinaison sup�rieurs
    for (auto it : inferieurs) {
        totalScore += it->avoir_score();
    }

    return this->totalScore;
}

//ajout d'une figure de type combinaison donc les 6 ou 5 etc
void Joueur::ajouter_superieurs(int* recap, int valeur)
{
    this->superieurs.at(valeur)->valider_figure(recap);
    std::cout << "Figure : " << this->superieurs.at(valeur)->avoir_nom() << " a bien ete ajouter" << std::endl;
}

//ajout d'une figure carre, brelan etc
void Joueur::ajouter_inferieurs(int* recap, int valeur)
{
    this->inferieurs.at(valeur)->valider_figure(recap);
    std::cout << "Figure : " << this->inferieurs.at(valeur)->avoir_nom() << " a bien ete ajouter" << std::endl;
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
    int recap[6];
    bool garde = false;

    //we get our values
    l.lance(des, NB_DE);
    this->avoir_recapitulatif(l.avoir_des(), recap);
    this->superieurs_restante(&superieurs_restant);
    this->inferieurs_restante(&inferieurs_possible, &inferieurs_impossible, recap);

    while (!garde && cpt_tour < this->yahtzee_g->avoir_nb_lancer())
    {
        // affichage des des 
        De** des = l.avoir_des();
        for (unsigned int i = 0; i < 5; i++)
            std::cout << des[i]->avoir_val() << " ";
        std::cout << std::endl;

        afficher_possibilite(recap, cpt_tour, inferieurs_possible, superieurs_restant);
        do
        {
            std::cin >> selected;
            if(cpt_tour < this->yahtzee_g->avoir_nb_lancer()-1)
                choice = choix_correct(selected, inferieurs_possible.size() + superieurs_restant.size() + 2, 1);
            else
                choice = choix_correct(selected, inferieurs_possible.size() + superieurs_restant.size() + 1, 1);
        }while (choice == -1);
        if (choice <= superieurs_restant.size()) //combinaison sup�rieur
        {
            this->ajouter_superieurs(recap, superieurs_restant.at(choice-1));
            garde = true;
        }
        else if(choice <= inferieurs_possible.size() + superieurs_restant.size())//combinaison inferieur 
        {
            this->ajouter_inferieurs(recap, inferieurs_possible.at(choice-superieurs_restant.size()-1));
            garde = true;
        }
        else if (choice == (inferieurs_possible.size() + superieurs_restant.size()+1))// abandonner une combinaison
        {
            choice = this->abandonne(recap, &inferieurs_impossible);
            garde = true;
            
        }
        else if(cpt_tour < 2)//Relancer les des si il peux encore les relancés max de cpt_tour
        {
            choice = this->relancer_des(l);
            this->avoir_recapitulatif(l.avoir_des(), recap);

            //On vide nos figures et on les recalcule
            superieurs_restant.clear();
            inferieurs_possible.clear();
            inferieurs_impossible.clear();
            this->superieurs_restante(&superieurs_restant);
            this->inferieurs_restante(&inferieurs_possible, &inferieurs_impossible, recap);
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

//affiche les possibilit�s en fonction des des
void Joueur::afficher_possibilite(int* recap, int cpt_tour, std::vector<int> inferieurs_possible, std::vector<int> superieurs_restant)
{
    int val = 1;

    std::cout << "Selectionnez ce que vous voulez valider : " << std::endl;
    //boucle sur les indexs_superieurs pour l'affichage
    for (int i = 0; i < superieurs_restant.size(); i++)
    {
        std::cout << val << ". " << this->superieurs.at(superieurs_restant.at(i))->avoir_nom() << " : "
            << this->superieurs.at(superieurs_restant.at(i))->score_possible(recap) << std::endl;
        val++;
    }
    
    //boucle sur les indexs_inferieurs pour l'affichage
    for (int i = 0; i < inferieurs_possible.size(); i++)
    {
        std::cout << val << ". " << this->inferieurs.at(inferieurs_possible.at(i))->avoir_nom() << " : " 
            << this->inferieurs.at(inferieurs_possible.at(i))->score_possible(recap) << std::endl;
        val++;
    }
    
    std::cout << val << ". Abandonne une possibilite" << std::endl;
    if (cpt_tour < 2)
        std::cout << (val + 1) << ". Relancer les des" << std::endl;
}

std::string Joueur::avoir_nom()
{
    return this->nom;
}

// remplis le vecteurs d'indexs passe en parametre apres les indexs des figures  
// superieurs non realise
void Joueur::superieurs_restante(std::vector<int>* indexs)
{
    for (unsigned int index = 0; index < superieurs.size(); index++) {
        if (!superieurs.at(index)->est_assigner())
            indexs->push_back(index);
    }
    indexs->shrink_to_fit();
}

// remplis le vecteurs d'indexs passe en parametre apres les indexs des figures  
// inferieurs non realise
void Joueur::inferieurs_restante(std::vector<int>* indexs_possible, std::vector<int>* indexs_impossible,
    int* recap)
{
    for (unsigned int index = 0; index < inferieurs.size(); index++) {
        if (!inferieurs.at(index)->est_assigner()) {
            if (inferieurs.at(index)->est_figure(recap))
                indexs_possible->push_back(index);
            else
                indexs_impossible->push_back(index);

        }
    }
    indexs_possible->shrink_to_fit();
    indexs_impossible->shrink_to_fit();
}

// V�rifie que le joueur ne rentre pas n'importe quoi dans ces choix, on veux un int entre 1 et max
int choix_correct(std::string selected, int max, int min)
{
    int number = -1;
    try
    {
        number = std::stoi(selected);
    }
    catch (std::invalid_argument)
    {
        std::cout << "Entrez un chiffre !" << std::endl;
    }
    if (number < min || number > max)
    {
        std::cout << "Entre un chiffre entre " << min << " et " << max << std::endl;
        return -1;
    }
    return number;
}

int Joueur::abandonne(int *recap, std::vector<int>* inferieurs_impossible)
{
    // affiche ce qu'il peut abandonner
    int choice = -1;
    std::string selected;

    std::cout << "Voici toutes les figures que vous pouvez abandonnez :" << std::endl;

    for (unsigned int index = 0; index < inferieurs_impossible->size(); index++) {
        std::cout << index+1 << ": " << inferieurs.at(inferieurs_impossible->at(index))->avoir_nom() << " ";
    }

    // il n'y a plus combinaison inf�rieur a abandonn�
    if (inferieurs_impossible->size() == 0) {
        std::cout << "Vous ne pouvez plus abandonner de combinaison" << std::endl;
        return choice;
    }

    while (choice == -1)
    {
        std::cout << "\nSelectionnez la figure que vous voulez abandonner (stop pour revenir en arriere)" << std::endl;
        std::cin >> selected;
        if (std::strcmp(selected.c_str(), "stop") == 0)
            return -1;
        choice = choix_correct(selected, inferieurs_impossible->size(), 1);
    }
    std::cout << "Figure : " << this->inferieurs.at(inferieurs_impossible->at(choice-1))->avoir_nom() << " a bien ete abandonnez" << std::endl;
    this->inferieurs.at(inferieurs_impossible->at(choice-1))->valider_figure(recap);
    return inferieurs_impossible->at(choice-1);
}

int Joueur::relancer_des(Lancer &l)
{
    int choice = -1;
    int* des_r = nullptr;
    std::string selected;

    std::cout << "Selectionner quel des vous voulez relancer, format attendu (123456) : " << std::endl;
    for (int i = 0; i < NB_DE ; i++) //boucle sur les d�s pour les affich�s
    {
        std::cout << "De " << i+1 << " : " << l.avoir_des()[i]->to_String() << std::endl;
    }
    std::cout << NB_DE+1 << ". revenir en arriere" << std::endl;

    //test le string en entier et boucle jusqu'a obtenir une bonne valeur
    do
    {
        std::cin >> selected;
        try
        {
            int n = std::stoi(selected);
            if (n == NB_DE+1)
                return -1;
        }
        catch (std::invalid_argument)
        {
            std::cout << "Please enter a number !" << std::endl;
        }
        des_r = this->des_relance(selected);
    } while (des_r == nullptr);

    if (des_r != nullptr)
    {
        l.lance(des_r, std::strlen(selected.c_str()));
        delete des_r;
    }
    return 0;
}

//fonction pour avoir un tableau de int avec tout les des et verifie que leur formats est correct
int* Joueur::des_relance(std::string des_r)
{
    int* relance = new int[std::strlen(des_r.c_str())]; // voila de la bonne allocation dynamique
    // pas de doublon, pas de des > 5 et < 1 et pas de lettres
    if (des_r.size() > NB_DE)
    {
        std::cout << "Erreur dans la chaine envoye, taille trop grande" << std::endl;
        return nullptr;
    }
    else
    {
        int number;
        for (unsigned int i = 0; i < des_r.size(); i++)
        {
            number = choix_correct(std::string(1, des_r[i]), NB_DE, 1);
            if (number == -1)
                return nullptr;
            else
                relance[i] = number;
        }

        //verifie les doublons
        for (unsigned int i = 0; i < des_r.size(); i++)
        {
            number = relance[i];
            for (unsigned int j = i+1; j < des_r.size(); j++)
            {
                if (number == relance[j])
                    return nullptr;
            }
        }
    }
    
    return relance;
}

void Joueur::avoir_recapitulatif(De** des, int* recap)
{
    // on fait le recapitulatif des valeurs obtenues
    for (unsigned int index = 0; index < 6; index++) {
        recap[index] = 0;
    }

    for (unsigned int index = 0; index < 5; index++) {
        recap[(des[index]->avoir_val() - 1)] ++;
    }
}