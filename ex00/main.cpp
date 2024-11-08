#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Invalid arguments" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
}
