#include <iostream>
#include <limits>

long long collatz_terms(long long n)
{
	long long count = 1;
	while (n > 1)
	{
		n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		++count;
	}
	return count;
}

int main()
{
	long long number_max = 1;
	long long chain_max = std::numeric_limits<long long>::min();
	for (int i = 1; i < 1000000; ++i)
	{
		long long chain = collatz_terms(i);
		if (chain > chain_max)
		{
			chain_max = chain;
			number_max = i;
		}
	}
	std::cout << number_max << " " << chain_max << std::endl;
	std::cin.get();
}

