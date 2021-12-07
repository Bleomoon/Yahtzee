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

	int values[6] = { 1, 2, 3, 4 ,5 ,6 };
	int possibilites_index = 0;
	const int current = values[1];

	/*Combinaison<current> current_combi();

	// combinaison sup�rieurs
	for (int value = 0; value < 6; value++) {
		const int current = values[value];
		auto current_combi = new Combinaison<current>(false);
	}*/


	return toutes_possibilites;
}

int* Lancer::lance(int* indiceslances)
{
	// on lance seulement les des d'ont l'indice est dans le tableau 
	int nb_des_lance = sizeof(indiceslances);
	for (int index_de = 0; index_de < nb_des_lance; index_de++)
	{
		des[indiceslances[index_de]].lance();
	}
}