#include <iostream>
#include <cmath>
using namespace std;

const int SUM = 1000;

void alt1();
void alt2();

int main()
{
	alt1();
}

// Euclid: a = m^2 - n^2; b = 2mn; c = m ^ 2 + n ^ 2
void alt1()
{
	for (int m = 1; m <= 1000; ++m)
	{
		for (int n = 1; n < m; ++n)
		{
			if (m * m + m * n == SUM / 2)
			{
				cout << fixed << (m * m - n * n) * (2 * m * n) * (m * m + n * n) << endl;
				return;
			}
		}
	}
}

void alt()
{
	for (int a = 1; a <= 1000; ++a)
	{
		for (int b = 1; b <= 1000; ++b)
		{
			if (a + b + sqrt(a * a + b * b) == SUM)
			{
				cout << fixed << a * b * sqrt(a * a + b * b) << endl;
				return;
			}
		}
	}
}