#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cerr << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &) {
	std::cerr << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cerr << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	std::cerr << "ScalarConverter copy assignement operator called" << std::endl;
	return (*this);
}

void ScalarConverter::convert(const std::string &input) {

}
