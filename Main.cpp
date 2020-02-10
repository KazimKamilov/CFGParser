#include "CFGParser.hpp"
#include <iostream>


int main()
{
	CFGParser cfg("test.ini");

	cfg.debug();
	
	std::cout << "Enter anything, and press Enter..." << std::endl;
	std::cin.get();
	
	return 0;
}
