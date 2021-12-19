#include "Chance.h"

Chance::Chance() : Figure() { }

bool Chance::valider_figure(int* des)
{
	if (est_figure(des)) {
		int somme = 0;
		for (int index = 0; index < 6; index++) {
			somme += des[index] *  (index +1) ;
		}

		this->score = somme;
		this->assigner = true;

		return true;
	}

	return false;
}

bool Chance::est_figure(int* des)
{
	return true;
}

int Chance::score_possible(int* recap)
{
	int somme = 0;
	for (int index = 0; index < 6; index++) {
		somme += recap[index] * (index + 1);
	}

	return somme;
}

std::string Chance::avoir_nom()
{
	return "Chance";
}

std::ostream& operator<<(std::ostream& out, const Chance& figure)
{
	out << "Chance";

	return out;
}
