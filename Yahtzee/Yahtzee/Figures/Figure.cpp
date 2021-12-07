#include "Figure.h"

std::ostream& operator<<(std::ostream& out, Figure& figure)
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

Figure::Figure()
{
	abandonne = false;
	assigner = false;
	score = 0;
}

int Figure::get_score()
{
	return score;
}

bool Figure::is_assigner()
{
	return assigner;
}
