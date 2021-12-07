#include "Lancer.h"

// TODO forme canonique

Lancer::Lancer() 
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
	{
		for (int i = 0; i < sizeof(copy.des); i++)
			this->des[i] = copy.des[i];
	}
}

/* ça sert à quelquechose maintenant? non 
std::vector<Figure*>& Lancer::possibilite(Joueur* j)
{
	std::vector<Figure*> toutes_possibilites;
	toutes_possibilites.reserve(13);

	// on fait le recapitulatif des valeurs obtenues
	int recap[6];
	for (int current : recap) {
		current = 0;
	}

	for (int index = 0; index < 6; index++) {
		recap[des[index].get_val() - 1] ++;
	}

	const int values[6] = { 1, 2, 3, 4 ,5 ,6 };
	int possibilites_index = 0;
	// combinaison sup�rieurs
	for (int value = 0; value < 6; value++) {
		auto current_combi = new Combinaison<const_cast<int&>(values[value])>(false);
	}

	return toutes_possibilites;
}*/

void Lancer::lance(int* indiceslances)
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