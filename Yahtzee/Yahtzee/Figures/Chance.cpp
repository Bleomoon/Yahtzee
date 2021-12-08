#include "Chance.h"

Chance::Chance() : Figure() { }

bool Chance::set_figure(int* des)
{
	if (is_figure(des)) {
		int somme = 0;
		for (int index = 0; index < 5; index++) {
			somme += des[index];
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

std::string Chance::get_name()
{
	return "Chance";
}

std::ostream& operator<<(std::ostream& out, const Chance& figure)
{
	out << "Chance";

	return out;
}
