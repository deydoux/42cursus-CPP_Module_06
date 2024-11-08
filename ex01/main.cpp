#include "Serializer.hpp"

int main() {
	Data *ft = new Data;
	uintptr_t ftRaw = Serializer::serialize(ft);
	ft->i = 42;
	ft->s = "42";
	std::cout << Serializer::deserialize(ftRaw)->i << " " << Serializer::deserialize(ftRaw)->s << std::endl;
	delete ft;

	uintptr_t toRaw = Serializer::serialize(new Data);
	Data *to = Serializer::deserialize(toRaw);
	Serializer::deserialize(toRaw)->i = 21;
	Serializer::deserialize(toRaw)->s = "21";
	std::cout << to->i << " " << to->s << std::endl;
}
