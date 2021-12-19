#include "Brelan.h"

Brelan::Brelan()
{
}

bool Brelan::valider_figure(int* recap)
{
	assigner = true;
	// trouver un brelan
	if (est_figure(recap)) {
		// faire la somme des dés
		for (int i = 0; i < 6; i++) {
			score += recap[i] * (i + 1);
		}
		return true;
	}
	
	// la figure n'est pas possible donc abandon
	abandonne = true;
	return false;
}

bool Brelan::est_figure(int* recap)
{
	for (int i = 0; i < 6; i++) {
		if (recap[i] >= 3) 
			return true;
	}

	return false;
}

int Brelan::score_possible(int* recap)
{

	if (est_figure(recap)) {
		int ret = 0;
		for (int i = 0; i < 6; i++) {
			ret += recap[i] * (i + 1);
		}
		return ret;
	}
	return 0;
}

std::string Brelan::avoir_nom()
{
	return "Brelan";
}

std::ostream& operator<<(std::ostream& out, const Brelan& figure)
{
	out << "Brelan";

	return out;
}
