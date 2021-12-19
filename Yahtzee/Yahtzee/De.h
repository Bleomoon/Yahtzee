#ifndef _DE_H_
#define _DE_H_

#include <string>

class De
{
    int val;
public:
    De();
    De(const De& copy);
    void lance();
    int avoir_val();
    std::string to_String();
};
#endif