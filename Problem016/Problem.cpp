#define ull unsigned long long

#include <iostream>
#include <string>
#include <cmath>

const int EXPONENT = 60;

int sum_of_digits(ull n);

int main()
{
	ull number = std::pow(2, EXPONENT);
	std::cout << number << std::endl;
    std::cout << sum_of_digits(number) << std::endl;
    std::cin.get();
}

int sum_of_digits(ull n)
{
	std::string s = std::to_string(n);
	int sum = 0;
	for (char c : s)
	{
		sum += c - '0';
	}
	return sum;
}
