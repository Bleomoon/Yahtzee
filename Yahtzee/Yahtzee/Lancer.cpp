#include "Lancer.h"
#include "Yahtzee_jeux.h"
#include <thread>
#include <chrono>

Lancer::Lancer(const int NB_DE) : indice_rand(0)
{
	des = new De * [NB_DE];
	for (int i = 0; i < NB_DE; i++) {
		des[i] = new De;
	}
}

Lancer::Lancer(const Lancer& copy) : indice_rand(0)
{
	if (this != &copy)
	{
		delete des;
		*des = new De[NB_DE];
		for (int i = 0; i < NB_DE; i++)
			this->des[i] = copy.des[i];
	}
}

Lancer::~Lancer()
{
	for (int i = 0; i < NB_DE; i++) {
		des[i] = new De;
	}
	delete[] des;
}

//TODO a finir
Lancer& Lancer::operator=(const Lancer& copy)
{
	if (this != &copy)
	{
		delete des;
		*des = new De[NB_DE];
		for (int i = 0; i < NB_DE; i++)
			this->des[i] = copy.des[i];
	}
	return *this;
}

void Lancer::lance(int* indiceslances, int nb_de)
{
	// on lance seulement les des d'ont l'indice est dans le tableau 
	for (int index_de = 0; index_de < nb_de; index_de++)
	{
		this->des[(indiceslances[index_de]-1)]->lance(this->indice_rand);
		this->indice_rand++;
	}
}

De** Lancer::avoir_des()
{
	return this->des;
}