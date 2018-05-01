#include "morse_code.h"
#include <iostream>

int main() {
	morse_code m;
	std::string test = m.encode("Hello");
	std::cout << test;
	std::string test2 = m.decode(test);
	std::cout << test2;
	return 0;
}
