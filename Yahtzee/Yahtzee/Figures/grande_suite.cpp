#include "Grande_suite.h"

bool Grande_suite::valider_figure(int* recap)
{
	assigner = true;

	if (est_figure(recap)) {
		score = 40;
		return true;
	}

	abandonne = true;
	return false;
}

bool Grande_suite::est_figure(int* recap)
{
	int cpt_suite = 0;

	for (int i = 0; i < 6; i++) {
		if (recap[i] > 1)
			return false;
		else if (recap[i] == 1)
			cpt_suite++;
		else if (i != 5)
			cpt_suite = 0;
	}

	return cpt_suite == 5;
}

int Grande_suite::score_possible(int* recap)
{
	if (est_figure(recap))
		return 40;
	
	return 0;
}

std::string Grande_suite::avoir_nom()
{
	return "Grande Suite";
}

std::ostream& operator<<(std::ostream& out, const Grande_suite& figure)
{
	out << "Grande Suite";

	return out;
}
