#include "Lancer.h"
#include "Yahtzee_game.h"
#include <thread>
#include <chrono>
#include "Invalid_index_exception.h"

// fit une allocation mémoire de NB_DE, tous les des sont a initialisé a valeur = 0
Lancer::Lancer(const int NB_DE): nb_de(NB_DE)
{
	srand(time(NULL));
	des = new De * [NB_DE];
	for (int i = 0; i < NB_DE; i++) {
		des[i] = new De;
	}
}

// constructeur par copie
Lancer::Lancer(const Lancer& copy) : nb_de(copy.nb_de)
{
	srand(time(NULL));
	des = new De * [nb_de];
	for (int i = 0; i < nb_de; i++)
		this->des[i] = new De(*copy.des[i]);
}

// destructeur
Lancer::~Lancer()
{
	for (int i = 0; i < nb_de; i++) {
		delete des[i];
	}
	delete[] des;
}

// surcharge de l'opérateur égale
Lancer& Lancer::operator=(const Lancer& copy)
{
	if (this != &copy)
	{
		srand(time(NULL));
		// destruction des des
		for (int i = 0; i < nb_de; i++)
			delete des[i];
		delete[] des;

		nb_de = copy.nb_de;
		des = new De * [nb_de];
		for (int i = 0; i < nb_de; i++)
			this->des[i] = new De(*copy.des[i]);

	}
	return *this;
}

// lances les dés qui pour on leur indice contenue dans le tableau
void Lancer::lance(int* indiceslances, int nb_indice)
{
	// on lance seulement les des d'ont l'indice est dans le tableau 
	for (int index_de = 0; index_de < nb_indice; index_de++)
	{
		// index invalide
		if (indiceslances[index_de] < 1 || indiceslances[index_de] > nb_de)
			throw Invalid_index_exception("Out of Bounds");

		this->des[(indiceslances[index_de]-1)]->lance();
	}
}

// revois le tableau de dé
De** Lancer::get_des()
{
	return this->des;
}