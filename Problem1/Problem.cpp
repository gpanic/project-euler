#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE_EXCLUSIVE = 1000;

int alt1();

int main()
{
	int sum = 0;
	for (int i = 0; i < MAX_SIZE_EXCLUSIVE; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}


// Arithmetic series
// n (a1 + an) / 2
int alt1()
{
	int max = MAX_SIZE_EXCLUSIVE - 1;
	int multiples3 = (int)floor(max / 3.0);
	int multiples5 = (int)floor(max / 5.0);
	int multiples15 = (int)floor(max / 15.0);
	int sum3 = 3 * multiples3 * (1 + multiples3) / 2;
	int sum5 = 5 * multiples5 * (1 + multiples5) / 2;
	int sum15 = 15 * multiples15 * (1 + multiples15) / 2;
	return sum3 + sum5 - sum15;
}