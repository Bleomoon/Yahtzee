#ifndef _DE_H_
#define _DE_H_

#include <string>

class De
{
    int val;
public:
    De();
    De(const De& copy);
    int get_val();
    void lance();
    std::string to_String();
};
#endif