#include "Brelan.h"

Brelan::Brelan()
{
}

bool Brelan::set_figure(int* recap)
{
	assigner = true;
	// trouver un brelan
	if (is_figure(recap)) {
		// faire la somme des dés
		for (int i = 0; i < sizeof(recap); i++) {
			score += recap[i] * (i + 1);
		}
		return true;
	}
	
	// la figure n'est pas possible donc abandon
	abandonne = true;
	return false;
}

bool Brelan::is_figure(int* recap)
{
	for (int i = 0; i < sizeof(recap); i++) {
		if (recap[i] >= 3) 
			return true;
	}

	return false;
}

std::string Brelan::get_name()
{
	return "Brelan";
}

std::ostream& operator<<(std::ostream& out, const Brelan& figure)
{
	out << "Brelan";

	return out;
}
