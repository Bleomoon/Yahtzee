#include "Figure.h"

Figure::Figure()
{
	abandonne = false;
	assigner = false;
	score = 0;
}

int Figure::avoir_score()
{
	return score;
}

bool Figure::est_assigner()
{
	return assigner;
}

std::ostream& operator<<(std::ostream& out, const Figure& figure)
{
	out << "figure ";
	if (figure.assigner) {
		if (figure.abandonne)
			out << "est abandonné !";
		else
			out << "a pour score " << figure.score;
	}
	else
		out << " n'est pas assigné !";

	return out;
}