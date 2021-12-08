#include "Chance.h"

Chance::Chance() : Figure() { }

bool Chance::set_figure(int* des)
{
	if (is_figure(des)) {
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

bool Chance::is_figure(int* des)
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

std::string Chance::get_name()
{
	return "Chance";
}

std::ostream& operator<<(std::ostream& out, const Chance& figure)
{
	out << "Chance";

	return out;
}
