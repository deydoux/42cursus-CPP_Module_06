#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

class ScalarConverter {
private:
	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);
	static bool isLiteral(const std::string &input);
	static bool isLiteralF(const std::string &input);
	static int convertChar(const std::string &input);
	static int convertInt(const std::string &input);
	static int convertFloat(const std::string &input);
	static int convertDouble(const std::string &input);
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &rhs);
	virtual void pureVirtualFunction() const = 0;
	static int convert(const std::string &input);
};

#endif
