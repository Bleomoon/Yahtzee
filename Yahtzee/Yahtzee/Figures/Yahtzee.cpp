#include "Yahtzee.h"

bool Yahtzee::set_figure(int* recap)
{
    assigner = true;

    if (is_figure(recap)) {
        score = 50;
        return true;
    }

    abandonne = true;
    return false;
}

bool Yahtzee::is_figure(int* recap)
{
    for (int i = 0; i < sizeof(recap); i++) {
        if (recap[i] == 5)
            return true;
    }


    return false;
}

std::string Yahtzee::get_name()
{
    return "Yathzee";
}

std::ostream& operator<<(std::ostream& out, Yahtzee& figure)
{
    out << "Yathzee";

    return out;
}