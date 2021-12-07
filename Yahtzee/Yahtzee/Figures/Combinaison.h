#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_

#include "Figure.h"
#include "../Yahtzee_game.h"

template<int valeur>
class Combinaison : public Figure
{
	int repetitions;
public:
	Combinaison() : Figure() 
	{ 
		repetitions = 0; 
	}

    bool set_figure(int* recap)
    {
		score = valeur * recap[valeur - 1];
		assigner = true;
    }

    bool is_figure(int* recap)
    {
        return true;
    }

    std::string get_name()
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
    
    int get_score()
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
