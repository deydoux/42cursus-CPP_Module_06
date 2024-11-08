#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer {
public:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	virtual void pureVirtualFunction() const = 0;
	Serializer &operator=(const Serializer &rhs);
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
