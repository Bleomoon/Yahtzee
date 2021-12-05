#include "Lancer.h"

Lancer::Lancer() {};
Lancer::~Lancer() {};

std::vector<std::string> Lancer::possibilite(const Joueur* j)
{
	std::vector<std::string> all_possibilites;
	
	return all_possibilites;
}

int* Lancer::lance(int* indiceslances)
{
	int new_des[sizeof(indiceslances)];
	for (int i = 0; i < sizeof(indiceslances); i++)
	{
		new_des[i] = rand() % 6 + 1;
	}
	return new_des;
}