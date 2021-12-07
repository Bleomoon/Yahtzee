#include "Lancer.h"
#include "Yahtzee_game.h"

// TODO forme canonique

Lancer::Lancer(const int NB_DE)
{
	des = new De * [NB_DE];
	for (int i = 0; i < NB_DE; i++) {
		des[i] = new De;
	}
}

Lancer::~Lancer()
{
	for (int i = 0; i < NB_DE; i++) {
		des[i] = new De;
	}
	delete[] des;
}

Lancer& Lancer::operator=(const Lancer& copy)
{
	if (this != &copy)
		this->des = copy.des;
	return *this;
}

void Lancer::lance(int* indiceslances) const
{
	// on lance seulement les des d'ont l'indice est dans le tableau 
	for (int index_de = 0; index_de < sizeof(indiceslances); index_de++)
	{
		this->des[indiceslances[index_de]]->lance();
	}
}

De** Lancer::get_des()
{
	return this->des;
}