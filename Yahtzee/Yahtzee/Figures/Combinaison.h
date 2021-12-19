#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_

#include "Figure.h"

template<int valeur>
class Combinaison : public Figure
{
public:
	Combinaison() : Figure() 
	{ 
	}

    bool valider_figure(int* recap)
    {
		score = valeur * recap[valeur - 1];
		assigner = true;
		return assigner;
    }

    bool est_figure(int* recap)
    {
        return true;
    }

	int score_possible(int* recap)
	{
		return valeur * recap[valeur - 1];
	}

    std::string avoir_nom()
    {
		switch (valeur)
		{
		case 1:
			return "un";
			break;
		case 2:
			return "deux";
			break;
		case 3:
			return "trois";
			break;
		case 4:
			return "quatre";
			break;
		case 5:
			return "cinq";
			break;
		case 6:
			return "six";
			break;
		}
    }
    
    int avoir_score()
    {
        return this->score;
    }
};

template<int valeur> 
std::ostream& operator<<(std::ostream& out, const Combinaison<valeur>& figure)
{
	out << "Combinaison de " << valeur; 
	if (figure.assigner)
		" répété " << figure.repetitions << " fois pour un score de " << figure.score;
	else
		" n'est pas assigné !";

	return out;
}

#endif
