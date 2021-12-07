#include "Petite_suite.h"

bool Petite_suite::set_figure(int* recap)
{
	assigner = true; 

	if (is_figure(recap)) {
		score = 30;
		return true;
	}

	abandonne = true;
	return false;
}

bool Petite_suite::is_figure(int* recap)
{
	int cpt_suite = 0;
	// TODO refaire
	for (int i = 0; i < sizeof(recap); i++) {
		if (recap[i] >= 1)
			cpt_suite++;
		else if (recap[i] == 0 && (i == 0 || i == 1))
			cpt_suite = 0;
	}

	return cpt_suite >= 4;
}

std::string Petite_suite::get_name()
{
	return "Petite Suite";
}

std::ostream& operator<<(std::ostream& out, Petite_suite& figure)
{
	out << "Petite Suite";

	return out;
}
