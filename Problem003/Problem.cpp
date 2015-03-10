#include <iostream>
#include <cmath>
using namespace std;

const long long NUMBER = 600851475143;

int main()
{
	long long number = NUMBER;
	int factor = 0;

	while (number % 2 == 0)
	{
		number /= 2;
		factor = 2;
	}

	for (int i = 3; i <= sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			number /= i;
			factor = i;
		}
	}

	if (number > 2)
	{
		factor = number;
	}

	cout << factor << endl;
}