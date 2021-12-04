#include <iostream>

#include "figure.hpp"
#include "carre.hpp"
#include "brelan.hpp"
#include "chance.hpp"
#include "grande_suite.hpp"
#include "petite_suite.hpp"
#include "yahtzee.hpp"
#include "full.hpp"

class player
{
    int totalScore;
    figure all_figure[7];
    int combinaisons[6];
public:
    player();
    ~player();
    int get_totalScore();
    bool add_combinaison(int pos); //combinaisaon ?
    bool add_figure(figure f);
    int sum_combinaison();

}