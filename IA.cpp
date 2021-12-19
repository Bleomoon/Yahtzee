#include "IA.h"
#include "Joueur.h"
#include "Yahtzee_jeux.h"

IA::IA(Yahtzee_jeux* jeu, std::string nom) : Joueur(jeu, nom)
{
	//crée les tableaux
	this->proba_base.reserve(6);
	this->proba_deux.reserve(6);

	//On init le premier tableau, la proba d'avoir ces figures sur le premier lancé
	this->proba_base.push_back(1200 / 7776); // Brelan
	this->proba_base.push_back(960 / 7776); // Petite suite
	this->proba_base.push_back(240 / 7776); // Grande suite
	this->proba_base.push_back(300 / 7776); // Full
	this->proba_base.push_back(150 / 7776); // Carre
	this->proba_base.push_back(6 / 7776); // Yahtzee

	//remplie de 0
	for (int i = 0; i < 6; i++)
		this->proba_deux.push_back(0);
}

IA::IA(const IA& copy) : Joueur(copy)
{
	if(this != &copy)
	{
		this->proba_base = copy.proba_base;
		this->proba_deux = copy.proba_deux;
	}
}

IA::~IA()
{
	//this->~Joueur();
	this->proba_base.clear();
	this->proba_deux.clear();
}

IA& IA::operator=(const IA& copy)
{
	if (this != &copy)
	{
		this->proba_base = copy.proba_base;
		this->proba_deux = copy.proba_deux;
	}
	return *this;
}

//On recupere la valeur des dés
double IA::get_score(int* recap)
{
	double score = 1;

	for (int i = 0; i < 6; i++)
	{
		if (recap[i] == 2 && score == 3) // full
			score = 3.5;
		else if (recap[i] == 2 && score == 2)//double pair
			score = 2.5;
		else if (recap[i] == 2) // Pair
			score = 2;
		else if (recap[i] == 3 && score == 2) //Full
			score = 3.5;
		else if (recap[i] == 3) //brelan
			score = 3;
		else if (recap[i] == 4)//carre
			score = 4;
		else if (recap[i] == 5)//Yahtzee
			score = 5;
	}
	return score;
}

//combien de dés se suivent
void IA::nb_suivie(int* recap, std::vector<int>* nb_suivie)
{

	int nb = 0;

	for (int i = 0; i < 6; i++)
	{
		while (recap[i + nb] != 0 && i + nb < 6)
			if (i + nb < 6)
				nb++;
		if (nb > nb_suivie->size())
		{
			nb_suivie->clear();
			for (int j = 0; j < nb; j++)
			{
				nb_suivie->push_back(i + j + 1);
			}
		}
		nb = 0;
	}
}

//On init le deuxieme tableau, la proba d'avoir des figures en fonctions des dés déja existant sur le prochaine lancé
//stats fait maison à la main
void IA::stat_prochaine_lancer(int* recap)
{
	double score = this->get_score(recap);
	std::vector<int> nb_suiv;
	this->nb_suivie(recap, &nb_suiv);

	//ensemble des dés différents
	if (score == 1) // on considère qu'on relance tout pour l'instant
	{
		this->proba_deux[0] = 1200. / 7776.; // Brelan
		this->proba_deux[3] = 300. / 7776.; // Full
		this->proba_deux[4] = 150. / 7776.; // Carre
		this->proba_deux[5] = 6. / 7776.; // Yahtzee	
	}
	else if (score == 2) // une paire
	{
		this->proba_deux[0] = 60. / 216.; // Brelan
		this->proba_deux[3] = 20. / 216.; // Full
		this->proba_deux[4] = 16. / 216.; // Carre
		this->proba_deux.at(5) = 1. / 216.; // Yahtzee
	}
	else if (score == 2.5) //deux paires
	{
		this->proba_deux.at(0) = 1. / 3.; // Brelan
		this->proba_deux.at(3) = 1. / 3.; // Full
		this->proba_deux.at(4) = 16. / 36.; // Carre
		this->proba_deux.at(5) = 1. / 36.; // Yahtzee
	}
	else if (score == 3) //un brelan
	{
		this->proba_deux.at(0) = 1.; // Brelan
		this->proba_deux.at(3) = 1. / 6.; // Full
		this->proba_deux.at(4) = 1. / 3.; // Carre
		this->proba_deux.at(5) = 1. / 36.; // Yahtzee
	}
	else if (score == 3.5) //un full
	{
		this->proba_deux.at(0) = 1.; // Brelan
		this->proba_deux.at(3) = 1.; // Full
		this->proba_deux.at(4) = 1. / 3.; // Carre
		this->proba_deux.at(5) = 1. / 36.; // Yahtzee
	}
	else if (score == 4) // carré
	{
		this->proba_deux.at(0) = 1.; // Brelan
		this->proba_deux.at(3) = 1. / 6.; // Full
		this->proba_deux.at(4) = 1.; // Carre
		this->proba_deux.at(5) = 1. / 6.; // Yahtzee
	}
	else if (score == 5) //un yahtzee
	{
		this->proba_deux.at(0) = 1.; // Brelan
		this->proba_deux.at(3) = 5. / 36.; // Full
		this->proba_deux.at(4) = 1.; // Carre
		this->proba_deux.at(5) = 1.; // Yahtzee
	}

	//Stats sur les suites, on voit quel suite on a 2,3,4 ou 2,3 etc
	if (nb_suiv.size() == 1) //on relance tout
	{
		this->proba_deux.at(1) = 960. / 7776.; // Petite suite
		this->proba_deux.at(2) = 240. / 7776.; // Grande suite
	}
	if (nb_suiv.size() == 2)
	{
		if (nb_suiv.at(0) == 3 && nb_suiv.at(0) == 4) // 3 et 4
		{
			this->proba_deux.at(1) = 102. / 216.; // Petite suite
			this->proba_deux.at(2) = 12. / 216.; // Grande suite
		}
		else
		{
			this->proba_deux.at(1) = 36. / 216.; // Petite suite
			this->proba_deux.at(2) = 6. / 216.; // Grande suite
		}
	}
	else if (nb_suiv.size() == 3)
	{
		if (nb_suiv.at(0) == 1 || nb_suiv.at(nb_suiv.size()-1) == 6)
		{
			this->proba_deux.at(1) = 1. / 3.; // Petite suite
			this->proba_deux.at(2) = 1. / 6.; // Grande suite
		}
		else
		{
			this->proba_deux.at(1) = 24. / 36.; // Petite suite
			this->proba_deux.at(2) = 1. / 18.; // Grande suite
		}
	}
	else if (nb_suiv.size() == 4)
	{
		this->proba_deux.at(1) = 1.; // Petite suite
		// Grande suite
		if (nb_suiv.at(0) == 1 || nb_suiv.at(nb_suiv.size()-1) == 6)
			this->proba_deux.at(2) = 1. / 3.; 
		else
			this->proba_deux.at(2) = 24. / 36.;
	}
	else if (nb_suiv.size() == 5)
	{
		this->proba_deux.at(2) = 1.; // Grande suite
		this->proba_deux.at(1) = 1.; // Petite suite
	}
}

//on retourne l'indice de la figure ainsi que sa proba (toujours la + haute)
int IA::extraire_max(int cpt_tour)
{
	double max = 0.0;
	int index = -1;
	for (int i = 0; i < this->proba_deux.size(); i++)
	{
		if (this->proba_deux.at(0) == 1 && cpt_tour == 2) //si dernier tour et brelan == 100% alors on prend en compte le brelan sinon on relance dans tout les cas au mieux
		{
			if (max < this->proba_deux.at(i) && this->inferieurs.at(i+1)->is_assigner() == false)
			{
				max = this->proba_deux.at(i);
				index = i;
			}
		}
		else if (this->proba_deux.at(4) == 1 && cpt_tour == 1)  //si avant dernier tour et carre == 100% alors on prend en compte le carre sinon on relance dans tout les cas au mieux
		{
			if (max < this->proba_deux.at(i) && this->inferieurs.at(i + 1)->is_assigner() == false)
			{
				max = this->proba_deux.at(i);
				index = i;
			}
		}
		else if (max < this->proba_deux.at(i) && this->inferieurs.at(i+1)->is_assigner() == false)
		{
			max = this->proba_deux.at(i);
			index = i;
		}
	}
	return index;
}

//parcours les 3 tableaux et supprime les probas pour l'ensemble des tableaux
void IA::delete_figure(int colonne)
{
	this->proba_base.erase(this->proba_base.begin() + colonne);
	this->proba_deux.erase(this->proba_deux.begin() + colonne);
}

void IA::tour_joueur(Lancer& l)
{
	std::cout << "Debut du tour de " << this->nom << std::endl;
	int cpt_tour = 0;
	double index_max = -1.;
	std::vector<int> inferieurs_possible, inferieurs_impossible, superieurs_restant;
	int des[5] = { 1, 2, 3, 4, 5 };
	int recap[6];
	bool garde = false;

	//on lance les dés
	l.lance(des, NB_DE);
	
	while (!garde && cpt_tour < 3)
	{
		this->get_recapitulatif(l.avoir_des(), recap);
		superieurs_restant.clear();
		inferieurs_possible.clear();
		inferieurs_impossible.clear();
		this->superieurs_restante(&superieurs_restant);
		this->inferieurs_restante(&inferieurs_possible, &inferieurs_impossible, recap);
		//si dernier lancé effectué
		if (cpt_tour == 2)
		{
			//cette fonction cherche la figure à valider pour maximisé les points sinon abandonne une figure en appelant abandonne et va aussi appelé delete colonne
			this->get_meilleur_figure(&inferieurs_possible, &inferieurs_impossible, &superieurs_restant, recap, index_max);
			garde = true;
		}
		else
		{
			this->stat_prochaine_lancer(recap);
			index_max = this->extraire_max(cpt_tour);

			//on set figure et on sort, en exemple si on a un Yahtzee on relance pas
			if (this->proba_deux.at(index_max) == 1)
			{
				//cette fonction cherche la figure à valider pour maximisé les points sinon abandonne une figure en appelant abandonne et va aussi appelé delete colonne
				this->get_meilleur_figure(&inferieurs_possible, &inferieurs_impossible, &superieurs_restant, recap, index_max);
				garde = true;
			}
			else //on relance les dés
			{
				std::cout << "L'IA relance les dés " << std::endl;
				this->relancer(l, recap, index_max);
			}
			index_max = -1.;
		}
		cpt_tour++;
	}

	std::cout << "Fin du tour pour " << this->nom << "\n" << std::endl;
}

void IA::get_meilleur_figure(std::vector<int>* inferieurs_possible, std::vector<int>* inferieurs_impossible, std::vector<int>* superieurs_restant, int* recap, int index_max)
{
	// on valide la meilleur figure possible
	if (index_max == -1)
	{
		int score_max = 0, index;
		bool sup = false;

		if (inferieurs_possible->size() > 0)
			index = inferieurs_possible->at(0);
		else
			index = superieurs_restant->at(0);

		for (int i = 0; i < inferieurs_possible->size(); i++)
		{
			if (score_max < this->inferieurs.at(inferieurs_possible->at(i))->score_possible(recap))
			{
				score_max = this->inferieurs.at(inferieurs_possible->at(i))->score_possible(recap);
				index = inferieurs_possible->at(i);
			}
		}
		for (int i = 0; i < superieurs_restant->size(); i++)
		{
			if (score_max < this->superieurs.at(superieurs_restant->at(i))->score_possible(recap))
			{
				score_max = this->superieurs.at(superieurs_restant->at(i))->score_possible(recap);
				index = superieurs_restant->at(i);
				sup = true;
			}
		}
		if (sup)
		{
			std::cout << "L'IA : " << this->nom << " décide de garder " << this->superieurs.at(index)->get_name() << std::endl;
			this->ajouter_superieurs(recap, index);
		}
		else
		{
			std::cout << "L'IA : " << this->nom << " décide de garder " << this->inferieurs.at(index)->get_name() << std::endl;
			this->ajouter_inferieurs(recap, index);
		}
	}
	else //on valide la figure désigner par index_max
	{
		std::cout << "L'IA : " << this->nom << " décide de garder " << this->inferieurs.at(index_max +1)->get_name() << std::endl;
		this->ajouter_inferieurs(recap, index_max + 1);
	}
}

void IA::relancer(Lancer& l, int* recap, double index_max)
{
	int* indiceslances;
	int nb_de = 0;

	//on relance les dés, avec des un tableau des positions des des et le nombre de des à relancer
	if (index_max == 1 || index_max == 3.5 || index_max == 4) //brelan, Full ou carre, on veux un full ou un carre
	{
		int max_de = 0;
		for (int i = 0; i < 6; i++)
			if (recap[i] > 2)
				max_de = i;
		if (index_max == 1 || index_max == 3.5) // on relance 2 des
			indiceslances = new int[2];
		else
			indiceslances = new int[1];
		for (int i = 0; i < NB_DE; i++)
		{
			if (l.avoir_des()[i]->avoir_val() != max_de)
			{
				indiceslances[nb_de] = i+1;
				nb_de++;
			}
		}
		l.lance(indiceslances, nb_de);
	}
	else if (index_max == 2)//Petite Suite, on veux la grande
	{
		//on forme la suite puis on cherche le dés manquant
		bool find = false;
		indiceslances = new int[1];
		std::vector<int> nb_suivie;
		this->nb_suivie(recap, &nb_suivie);

		for (int i = 0; i < NB_DE; i++)
		{
			int de = l.avoir_des()[i]->avoir_val();
			for (int j = 0; j < nb_suivie.size(); j++)
				if (nb_suivie.at(i) == de)
					find = true;
			if (find == false)
			{
				indiceslances[0] = i+1;
				l.lance(indiceslances, 1);
				break;
			}
			find = false;
		}
	}
	else
	{
		indiceslances = new int[5];
		for (int i = 0; i < 5; i++)
			indiceslances[i] = i+1;
		l.lance(indiceslances, 5);
	}
}