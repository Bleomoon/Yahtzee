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
	for (int i = 0; i < 6; i++) {
		if (recap[i] >= 1)
			cpt_suite++;
		else
			cpt_suite = 0;
		if (cpt_suite == 4)
			return true;
	}

	return false;
}

int Petite_suite::score_possible(int* recap)
{
	if(is_figure(recap))
		return 30;
	
	return 0;
}

std::string Petite_suite::get_name()
{
	return "Petite Suite";
}

std::ostream& operator<<(std::ostream& out, const Petite_suite& figure)
{
	out << "Petite Suite";

	return out;
}
