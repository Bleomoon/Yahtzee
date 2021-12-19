#include "Carre.h"

bool Carre::valider_figure(int* recap)
{
	assigner = true; 

	if (est_figure(recap)) {
		for (int i = 0; i < 6; i++) {
			score += recap[i] * (i + 1);
		}

		return true;
	}

	abandonne = true;
	return false;
}

bool Carre::est_figure(int* recap)
{
	// pour qu'il y est un carré il faut minimun 4 dés identiques
	for (int i = 0; i < 6; i++) {
		if (recap[i] >= 4) {
			return true;
		}
	}

	return false;
}

int Carre::score_possible(int* recap)
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

std::string Carre::avoir_nom()
{
	return "Carre";
}

std::ostream& operator<<(std::ostream& out, const Carre& figure)
{
	out << "Carre";

	return out;
}
