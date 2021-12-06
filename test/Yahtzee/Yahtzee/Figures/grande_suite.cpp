#include "Grande_suite.h"

bool Grande_suite::set_figure(int* recap)
{
	assigner = true;

	if (is_figure(recap)) {
		score = 40;
		return true;
	}

	abandonne = true;
	return false;
}

bool Grande_suite::is_figure(int* recap)
{
	int cpt_suite = 0;

	for (int i = 0; i < sizeof(recap); i++) {
		if (recap[i] >= 1)
			return false;
		else if (recap[i] == 1)
			cpt_suite++;
		else if (i != 5)
			cpt_suite = 0;
	}

	return cpt_suite == 5;
}

std::string Grande_suite::get_name()
{
	return "Grande Suite";
}

std::ostream& operator<<(std::ostream& out, Grande_suite& figure)
{
	out << "Grande Suite";

	return out;
}
