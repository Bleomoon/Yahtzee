#include "De.h"
#include <ctime>

// constructeur qui met la valeur du de a 0
De::De()
{
	this->val = 0;
}

// constructeur par copier les deux valeurs de des sont identiques
De::De(const De& copy) : val(copy.val)
{
}

// lance le de avec une valueur aleatoire entre 1 et 6 
void De::lance()
{
	this->val = (rand() % 6) + 1;
}

// retourne la valeur du dé
int De::get_val() { return val; }

std::string De::to_String()
{
	switch (this->val)
	{
	case 1:
		return "1";
		break;
	case 2:
		return "2";
		break;
	case 3:
		return "3";
		break;
	case 4:
		return "4";
		break;
	case 5:
		return "5";
		break;
	case 6:
		return "6";
		break;
	default:
		return "";
	}
	return "Dice value error";
};

