#include "Serializer.hpp"

Serializer::Serializer() {
	std::cerr << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &) {
	std::cerr << "Serializer copy constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cerr << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &) {
	std::cerr << "Serializer copy assignement operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
