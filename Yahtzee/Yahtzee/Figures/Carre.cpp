#include "Carre.h"

bool Carre::set_figure(int* recap)
{
	assigner = true; 

	if (is_figure(recap)) {
		for (int i = 0; i < sizeof(recap); i++) {
			score += recap[i] * (i + 1);
		}

		return true;
	}

	abandonne = true;
	return false;
}

bool Carre::is_figure(int* recap)
{
	// pour qu'il y est un carré il faut minimun 4 dés identiques
	for (int i = 0; i < sizeof(recap); i++) {
		if (recap[i] >= 4) {
			return true;
		}
	}

	return false;
}

std::string Carre::get_name()
{
	return "Carre";
}

std::ostream& operator<<(std::ostream& out, const Carre& figure)
{
	out << "Carre";

	return out;
}
