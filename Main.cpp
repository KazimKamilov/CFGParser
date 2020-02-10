#include "CFGParser.hpp"
#include <iostream>
#include <chrono>

int main()
{
	std::setlocale(LC_ALL, "Russian");
	
	auto begin = std::chrono::steady_clock::now();
	CFGParser cfg("test.ini");
	auto end = std::chrono::steady_clock::now();
	
	cfg.debug();
	
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	//cfg.debug();

	
	std::cout << "Enter anything, and press Enter..." << std::endl;
	std::cin.get();
	
	return 0;
}