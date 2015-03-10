#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000000;
const int NTH_PRIME = 10001;

int getNthPrime(int n);

int main()
{
	cout << getNthPrime(NTH_PRIME) << endl;
}

int getNthPrime(int n)
{
	bool sieve[MAX_NUMBER];
	fill_n(sieve, MAX_NUMBER, true);
	sieve[0] = sieve[1] = false;

	int primeCount = 0;
	int i = 2;
	while (i < MAX_NUMBER)
	{
		if (sieve[i])
		{
			primeCount++;
			if (primeCount == n)
			{
				return i;
			}
			for (int j = 2 * i; j < MAX_NUMBER; j += i)
			{
				sieve[j] = false;
			}
		}
		++i;
	}
	return -1;
}