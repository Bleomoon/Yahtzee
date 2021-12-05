#include "Figure.hpp"

Figure::Figure(bool abandonne, int score) : abandonne(abandonne), score(score) {};

int Figure::get_score()
{
    if (this->abandonne)
        return 0;
    else
        return score;
}

std::string Figure::get_name()
{
    return this->name;
}