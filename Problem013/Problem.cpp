#include <iostream>
#include "BigInt.h"

int main()
{
	std::ifstream file("Input.txt");

	std::string line;
	file >> line;
	BigInt sum(line);
	while (file >> line)
	{
		sum += BigInt(line);
	}
	std::cout << sum << std::endl;
	std::cout << sum.ToString().substr(0, 10) << std::endl;
	std::cin.get();
}