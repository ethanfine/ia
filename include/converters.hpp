#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <string>

//TODO "Converters" seems like a weird file separation - this should be put in the utils file...

std::string to_str(const int IN);

int to_int(const std::string& in);

//Intended for enum class Values, to retrieve the underlying type (e.g. int)
template <typename T>
typename std::underlying_type<T>::type to_underlying(T t);

#endif
