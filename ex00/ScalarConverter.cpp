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

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::isLiteral(const std::string &input) {
	return (input == "inf" || input == "+inf" || input == "-inf" || input == "nan");
}

bool ScalarConverter::isLiteralF(const std::string &input) {
	return (isLiteral(input) || input == "inff" || input == "+inff" || input == "-inff" || input == "nanf");
}

int ScalarConverter::convertChar(const std::string &input) {
	if (input.size() != 1 || std::isdigit(input[0]))
		return (1);
	std::stringstream ss(input);
	char c;
	ss >> c;
	printChar(static_cast<char>(c));
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
	return (0);
}

int ScalarConverter::convertInt(const std::string &input) {
	if (input.find('.') != std::string::npos || isLiteralF(input))
		return (1);
	std::stringstream ss(input);
	int i;
	ss >> i;
	if (!ss.eof() || ss.fail())
		std::cerr << "Int conversion impossible" << std::endl;
	else {
		printChar(static_cast<char>(i));
		printInt(static_cast<int>(i));
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	}
	return (0);
}

int ScalarConverter::convertFloat(const std::string &input) {
	if (input.empty() || input[input.size() - 1] != 'f' || isLiteral(input))
		return (1);
	char *end;
	float f = static_cast<float>(std::strtod(input.substr(0, input.size() - 1).c_str(), &end));
	if (*end) {
		std::cerr << "Float conversion impossible" << std::endl;
		return (0);
	}
	printChar(static_cast<char>(f));
	printInt(static_cast<int>(f));
	printFloat(static_cast<float>(f));
	printDouble(static_cast<double>(f));
	return (0);
}

int ScalarConverter::convertDouble(const std::string &input) {
	char *end;
	double d = std::strtod(input.c_str(), &end);
	if (*end) {
		std::cerr << "Double conversion impossible" << std::endl;
		return (0);
	}
	printChar(static_cast<char>(d));
	printInt(static_cast<int>(d));
	printFloat(static_cast<float>(d));
	printDouble(static_cast<double>(d));
	return (0);
}

int ScalarConverter::convert(const std::string &input) {
	return (!convertChar(input) || !convertInt(input) || !convertFloat(input) || !convertDouble(input));
}
