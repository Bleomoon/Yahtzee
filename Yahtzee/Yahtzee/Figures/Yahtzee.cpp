#include "Yahtzee.h"

bool Yahtzee::valider_figure(int* recap)
{
    assigner = true;

    if (est_figure(recap)) {
        score = 50;
        return true;
    }

    abandonne = true;
    return false;
}

bool Yahtzee::est_figure(int* recap)
{
    for (int i = 0; i < 6; i++) {
        if (recap[i] == 5)
            return true;
    }


    return false;
}

int Yahtzee::score_possible(int* recap)
{
    if (est_figure(recap))
        return 50;

    return 0;
}

std::string Yahtzee::avoir_nom()
{
    return "Yahtzee";
}

std::ostream& operator<<(std::ostream& out, const Yahtzee& figure)
{
    out << "Yahtzee";

    return out;
}