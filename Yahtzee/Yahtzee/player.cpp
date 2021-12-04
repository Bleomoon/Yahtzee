#include "player.hpp"

player::player()
{
    for(int i = 0; i < 7; i++)
    {
        this->all_figure[i] = 0;
    }
    for(int i = 0; i < 6; i++)
    {
        this->combinaisons[i] = 0;
    }
}

player::~player()
{
    std::cout << "Deletion of the player" << std::endl;
    for(int i = 0; i < std::sizeof(this->all_figure); i++)
    {
        delete this->all_figure[i];
    }
}

int player::get_totalScore()
{
    return this->totalScore;
}

bool player::add_combinaison(int pos, int score) //score ou les dés?
{
    if(this->combinaisons[pos] != 0)
        return false;
    else
        this->combinaisons[pos] = score;
    return true;
}

bool player::add_figure(figure f)
{
    /*ici on cherche le type de figure et on le met dans le tableau celon le type
    Brelan = pos 0
    Petite Suite = pos 1
    Grande suite = pos 2
    Full = pos 3
    Carré = pos 4
    Yahtzee = pos 5
    Chance = pos 6
    */
    return true;
}
    
int player::sum_combinaison()
{
    int sum = 0;
    for (int i = 0; i < std::sizeof(this->combinaisons); i++)
        sum+= this->combinaisons[i];
    return sum;
}