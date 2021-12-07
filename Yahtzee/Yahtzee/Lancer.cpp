#include "Lancer.h"

// TODO forme canonique

Lancer::Lancer(const int NB_DE)
{
	des = new De[NB_DE];
}

Lancer::~Lancer()
{
	delete[] des;
}

Lancer& Lancer::operator=(const Lancer& copy)
{
	if (this != &copy)
		this->des = copy.des;
}

void Lancer::lance(int* indiceslances) const
{
	// on lance seulement les des d'ont l'indice est dans le tableau 
	for (int index_de = 0; index_de < sizeof(indiceslances); index_de++)
	{
		this->des[indiceslances[index_de]].lance();
	}
}

De* Lancer::get_des()
{
	return this->des;
}