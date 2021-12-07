#include "De.h"

De::De()
{
	this->val = 0;
}

void De::lance()
{
	this->val = rand() % 6 + 1;
}

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
};

