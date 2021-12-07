#include "Yahtzee_game.h"

// constructeur ou on connais deja le nom de joureur a l'avance
Yahtzee_game::Yahtzee_game(int nb_joueurs, std::string nom_joueurs[],
	int nb_lancer_par_tours) : nb_joueur(nb_joueurs), nb_lancer(nb_lancer_par_tours)
{
	joueurs = new std::vector<Joueur*>;

	for (int i = 0; i < nb_joueur; i++) {
		Joueur j = Joueur(this, nom_joueurs[i]);
		joueurs->push_back(&j);
	}
	numero_tour = 0;
	lancer = new Lancer(NB_DE);
}

// constructeur on ne connais pas le nom des joureur, un scanner le demande le nombre de joueur pour la partie et leur nom
Yahtzee_game::Yahtzee_game(int nb_lancer_par_tours) : nb_lancer(nb_lancer_par_tours)
{
	nb_joueur = 0;


	// demande le nombre de joueur
	do {
		std::cout << "A combien voulez-vous jouer ? (entre 2 et 8)" << std::endl;
		std::cin >> nb_joueur;
	} while (nb_joueur < 2 || nb_joueur > 8);

	// allocation de la mémoire pour le tableau de joueur
	joueurs = new std::vector<Joueur*>;


	// demande tous les noms de joueurs
	std::string nom_joueur;
	for (int i = 0; i < nb_joueur; i++) {
		std::cin >> nom_joueur;
		Joueur* j = new Joueur(this, nom_joueur);
		joueurs->push_back(j);
	}

	numero_tour = 0;
	lancer = new Lancer(NB_DE);
}

//Constructeur par copie
Yahtzee_game::Yahtzee_game(const Yahtzee_game& copy)
	: nb_joueur(copy.nb_joueur), nb_lancer(copy.nb_lancer)
{
	joueurs = copy.joueurs;
	numero_tour = copy.numero_tour;
	lancer = new Lancer(NB_DE);
}

// destructeur
Yahtzee_game::~Yahtzee_game()
{
	// destruction de tous les joueur
	while (!joueurs->empty()) {
		delete &*joueurs->end();
		joueurs->pop_back();
	}
	delete[] joueurs;

	// destruction des dés
	delete lancer;
}

Yahtzee_game& Yahtzee_game::operator=(const Yahtzee_game& copy)
{
	if (this != &copy) {
		// destruction de tous les joueur pour éviter la fuite mémoire
		while (!joueurs->empty()) {
			delete&* joueurs->end();
			joueurs->pop_back();
		}
		delete[] joueurs;

		// copy des joueurs et des propriétés
		nb_joueur = copy.nb_joueur;
		nb_lancer = copy.nb_lancer;
		numero_tour = copy.numero_tour;
		joueurs = copy.joueurs;

		// on ne copie pas lancer car elle son contenue nous interesse pas TODO
	}

	return *this;
}

#include <algorithm>

void Yahtzee_game::jouer()
{
	// faire tous les tours
	for (numero_tour = 1; numero_tour <= 13; numero_tour++) {
		// chaque joueur joue
		for (int index_joueur = 0; index_joueur < nb_joueur; index_joueur++) {
			joueurs->at(index_joueur)->tour_joueur(*lancer);
		}
	}

	// on tri le tableau de joueurs par rapport a leurs socre
	struct {
		bool operator()(Joueur a, Joueur b) const { return (a.get_total_score() < b.get_total_score()); }
	} customLess;
	
	std::sort(joueurs->begin(), joueurs->end(), customLess);

	// affichage des joueurs
	std::cout << "rang : nom score" << std::endl;
	for (int index = 0; index < joueurs->size(); index++) {
		auto current = joueurs->at(index);
		std::cout << (index + 1) << ": " << current->get_nom() << " " << current->get_total_score() << std::endl;
	}
}

int Yahtzee_game::get_nb_lancer()
{
	return nb_lancer;
}
