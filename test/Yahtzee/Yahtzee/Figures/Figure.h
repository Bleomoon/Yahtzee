#ifndef _FIGURE_H_
#define _FIGURE_H_


#include <iostream>
#include <string>

class Figure
{
protected:
    bool abandonne;
    bool assigner; // si le joueur a ajouter la figure
    int score;
public:
    Figure();
    virtual bool set_figure(int* recap) = 0; // recap = le récapitulatif des dés 
    virtual bool is_figure(int* recap) = 0; // recap = le récapitulatif des dés 

    virtual std::string get_name() = 0;
    int get_score();
    bool is_assigner();

    friend std::ostream& operator<<(std::ostream& out, Figure& figure);
};

std::ostream& operator<<(std::ostream& out, Figure& figure);


#endif