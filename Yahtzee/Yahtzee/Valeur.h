#ifndef _VALEUR_H_
#define _VALEUR_H_

#include <string>

class Valeur
{
    int val;
public:
    Valeur(int v);
    ~Valeur();
    void lance();
    std::string to_String();
};
#endif