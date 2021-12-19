#ifndef _IA_H_
#define _IA_H_

#include <vector>
#include "Joueur.h"
#include "Lancer.h"

class IA : public Joueur
{
	std::vector<double> proba_base;
	std::vector<double> proba_deux;
public:
	IA(Yahtzee_jeux* jeu, std::string nom);
	IA(const IA& copy);
	~IA();
	IA& operator=(const IA& copy);
	double get_score(int* recap);
	void nb_suivie(int* recap, std::vector<int>* nb_suivie);
	void stat_prochaine_lancer(int* recap);
	int extraire_max(int cpt_tour);
	void delete_figure(int colonne);
	void tour_joueur(Lancer& l);
	void relancer(Lancer& l, int* recap, double index_max);
	void get_meilleur_figure(std::vector<int>* inferieurs_possible, std::vector<int>* inferieurs_impossible, std::vector<int>* superieurs_restant, int* recap, int index_max);

	//void abandonne(int* recap);
	
};

#endif