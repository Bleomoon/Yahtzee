#include "Full.h"

bool Full::set_figure(int* recap)
{
	assigner = true;

	if (is_figure(recap)) {
		score = 25;

		return true;
	}

	abandonne = true;
	return false;
}

bool Full::is_figure(int* recap)
{
	bool trois = false, deux = false;

	for (int i = 0; i < sizeof(recap); i++) {
		if (recap[i] == 2)
			deux = true;

		if (recap[i] == 3)
			trois = true;

		if (trois && deux)
			return true;
	}

	return false;
}

std::string Full::get_name()
{
	return "Full";
}

std::ostream& operator<<(std::ostream& out, Full& figure)
{
	out << "Full ";

	return out;
}
