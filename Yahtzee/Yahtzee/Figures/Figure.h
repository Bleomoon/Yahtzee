#ifndef _FIGURE_H_
#define _FIGURE_H_


#include <iostream>
#include <string>

class Figure
{
    const bool abandonne;
    const int score;
    std::string name;
public:
    Figure(bool abandonne, int score);
    virtual ~Figure() = 0;
    virtual std::string get_name();
    virtual int get_score() = 0;
};
#endif