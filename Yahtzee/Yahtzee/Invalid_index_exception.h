#ifndef _INVALID_INDEX_EXCEPTION_H_
#define _INVALID_INDEX_EXCEPTION_H_

#include <string>

class Invalid_index_exception
{
	const char* const data;
public:
	Invalid_index_exception(const char* const msg = 0) : data(msg) {};
};

#endif
