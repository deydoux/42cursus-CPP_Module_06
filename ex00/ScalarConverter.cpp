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

void ScalarConverter::printChar(char c) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

int ScalarConverter::convertChar(const std::string &input)
{
	if (input.size() != 1 || std::isdigit(input[0]))
		return (EXIT_FAILURE);
	std::stringstream ss(input);
	char c;
	ss >> c;
	printChar(static_cast<char>(c));
	std::cout << "int: " << static_cast<int>(c) << std::endl
		<< "float: " << static_cast<float>(c) << 'f' << std::endl
		<< "double: " << static_cast<double>(c) << std::endl;
	return (EXIT_SUCCESS);
}

int ScalarConverter::convertInt(const std::string &input) {
	if (input.find('.') != std::string::npos || input == "+inff" || input == "-inff")
		return (EXIT_FAILURE);
	std::stringstream ss(input);
	int i;
	ss >> i;
	if (!ss.eof() || ss.fail())
		std::cerr << "Int conversion impossible" << std::endl;
	else {
		printChar(static_cast<char>(i));
		std::cout << "int: " << static_cast<int>(i) << std::endl
			<< "float: " << static_cast<float>(i) << 'f' << std::endl
			<< "double: " << static_cast<double>(i) << std::endl;
	}
	return (EXIT_SUCCESS);
}

int ScalarConverter::convertFloat(const std::string &input) {
	if (input.empty() || input.back() != 'f' || input == "+inf" || input == "-inf")
		return (EXIT_FAILURE);
	std::stringstream ss(input.substr(0, input.size() - 1));
	float f;
	ss >> f;
	if (!ss.eof() || ss.fail())
		std::cerr << "Float conversion impossible" << std::endl;
	else {
		printChar(static_cast<char>(f));
		std::cout << "int: " << static_cast<int>(f) << std::endl
			<< "float: " << f << 'f' << std::endl
			<< "double: " << static_cast<double>(f) << std::endl;
	}
	return (EXIT_SUCCESS);
}

int ScalarConverter::convertDouble(const std::string &input) {
	std::stringstream ss(input);
	double d;
	ss >> d;
	if (!ss.eof() || ss.fail())
		std::cerr << "Double conversion impossible" << std::endl;
	else {
		printChar(static_cast<char>(d));
		std::cout << "int: " << static_cast<int>(d) << std::endl
			<< "float: " << static_cast<float>(d) << 'f' << std::endl
			<< "double: " << d << std::endl;
	}
	return (EXIT_SUCCESS);
}

int ScalarConverter::convert(const std::string &input) {
	return (!convertChar(input) || !convertInt(input) || !convertFloat(input) || !convertDouble(input));
}
