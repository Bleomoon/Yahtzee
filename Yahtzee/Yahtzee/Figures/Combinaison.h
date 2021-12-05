#ifndef _COMBINAISON_H_
#define _COMBINAISON_H_

#include "Figure.h"
#include "../Yahtzee_game.h"

template<int valeur>
class Combinaison : public Figure
{
    int repetition;
public:
    Combinaison(int rep) : repetition(rep), Figure(false, valeur * rep)
    {
        // TODO EXCEPTION
        // verification de la conformité des information entrées
        if (valeur < 1 || valeur > 6) {
            std::cerr << "Valeur incorect " << std::endl;
        }

        if (repetition < 0 || repetition > NB_DE) {
            std::cerr << "Nombre de répetition incorect " << std::endl;
        }
    }

    int get_score() {
        return valeur * repetition;
    }
};

#endif