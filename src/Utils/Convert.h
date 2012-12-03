#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <sstream>

template <class T>
inline std::string toString(const T &t){
	std::stringstream ss;
	ss << t;
	return ss.str();
}

#endif
