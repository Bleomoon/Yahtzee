#ifndef _DE_H_
#define _DE_H_

#include <string>

class De
{
    int val;
public:
    De();
    int get_val();
    void lance(int indice);
    std::string to_String();
};
#endif