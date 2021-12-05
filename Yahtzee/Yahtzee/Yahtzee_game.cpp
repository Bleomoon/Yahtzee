#include "Yahtzee_game.h"

// TODO forme canonique

// constructeur ou on connais deja le nom de joureur a l'avance
Yahtzee_game::Yahtzee_game(int nb_joueurs, std::string nom_joueurs[],
	int nb_lancer_par_tours) : nb_joueur(nb_joueurs), nb_lancer(nb_lancer_par_tours)
{
	joueurs = new Joueur * [nb_joueur];

	for (int i = 0; i < nb_joueur; i++) {
		joueurs[i] = new Joueur(this, nom_joueurs[i]);
	}
	numero_tour = 0;
	lancer = new Lancer;
}


// constructeur on ne connais pas le nom des joureur, un scanner le demande le nombre de joueur pour la partie et leur nom
Yahtzee_game::Yahtzee_game(int nb_lancer_par_tours) : nb_lancer(nb_lancer_par_tours)
{
	nb_joueur = 0;

	// demande le nombre de joueur
	do {
		std::cout << "A combien voulez-vous jouer ? (entre 2 et 8)" << std::endl;
		scanf("%d", &nb_joueur);
	} while (nb_joueur < 2 || nb_joueur > 8); 

	// allocation de la mémoire pour le tableau de joueur
	joueurs = new Joueur * [nb_joueur];

	// demande tous les noms de joueurs
	std::string nom_joueur;
	for (int i = 0; i < nb_joueur; i++) {
		scanf("%s", &nom_joueur);
		joueurs[i] = new Joueur(this, nom_joueur);
	}

	numero_tour = 0;
	lancer = new Lancer;
}

// destructeur
Yahtzee_game::~Yahtzee_game()
{
	// destruction de tous les joueur
	for (int i = 0; i < nb_joueur; i++) {
		delete joueurs[i];
	}
	delete[] joueurs;

	// destruction des dés
	delete lancer; 
}

void Yahtzee_game::jouer()
{
	for (numero_tour = 1; numero_tour <= 13; numero_tour++) {
		for (int index_joueur = 0; index_joueur < nb_joueur; index_joueur++) {

		}
	}
}
