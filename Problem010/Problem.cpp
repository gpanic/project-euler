#include <iostream>
#include <deque>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int MAX_NUMBER = 2000000;

long long getSumOfPrimes();
bool isPrime(int n);

int main()
{
	cout << getSumOfPrimes() << endl;
}

long long getSumOfPrimes()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	int i = 2;
	int sum = 0;
	while (i < MAX_NUMBER)
	{
		if (isPrime(i))
		{
			sum += i;
		}
		++i;
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << duration / 1000.0 << endl;

	return sum;
}

bool isPrime(int n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	int upper = (int)sqrt(n);
	int factor = 5;
	while (factor <= upper)
	{
		if (n % factor == 0)
			return false;
		factor += 2;
	}
	return true;
}