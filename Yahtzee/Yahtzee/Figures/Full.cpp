#include "Full.h"

bool Full::valider_figure(int* recap)
{
	assigner = true;

	if (est_figure(recap)) {
		score = 25;

		return true;
	}

	abandonne = true;
	return false;
}

bool Full::est_figure(int* recap)
{
	bool trois = false, deux = false;

	for (int i = 0; i < 6; i++) {
		if (recap[i] == 2)
			deux = true;

		if (recap[i] == 3)
			trois = true;

		if (trois && deux)
			return true;
	}

	return false;
}

int Full::score_possible(int* recap)
{
	if (est_figure(recap))
		return 25;

	return 0;
}

std::string Full::avoir_nom()
{
	return "Full";
}

std::ostream& operator<<(std::ostream& out, const Full& figure)
{
	out << "Full ";

	return out;
}
