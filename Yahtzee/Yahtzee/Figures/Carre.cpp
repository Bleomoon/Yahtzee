#include "Carre.h"

bool Carre::set_figure(int* recap)
{
	assigner = true; 

	if (is_figure(recap)) {
		for (int i = 0; i < 6; i++) {
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
	for (int i = 0; i < 6; i++) {
		if (recap[i] >= 4) {
			return true;
		}
	}

	return false;
}

int Carre::score_possible(int* recap)
{
	int ret = 0;
	for (int i = 0; i < 6; i++) {
		ret += recap[i] * (i + 1);
	}

	return ret;
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
