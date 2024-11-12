#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	switch (std::rand() % 3) {
	case 0:
		return (new A);
	case 1:
		return (new B);
	default:
		return (new C);
	}
}

void identify(Base *p) {
	if (!p)
		std::cout << "Can't identify null ptr" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "Identified A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified C" << std::endl;
	else
		std::cout << "Can't identify Base inheritance" << std::endl;
}

void identify(Base &p) {
	try {
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "Identified A" << std::endl;
		return ;
	} catch (std::bad_cast &) {}
	try {
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "Identified B" << std::endl;
		return ;
	} catch (std::bad_cast &) {}
	try {
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "Identified C" << std::endl;
		return ;
	} catch (std::bad_cast &) {}
	std::cout << "Can't identify Base inheritance" << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	A a;
	identify(a);
	identify(&a);

	B b;
	identify(b);
	identify(&b);

	C c;
	identify(c);
	identify(&c);

	Base base;
	identify(base);
	identify(&base);

	identify(NULL);

	for (size_t i = 0; i < 10; i++) {
		Base *abc = generate();
		identify(abc);
		identify(*abc);
		delete abc;
	}
}
