#include <iostream>
using namespace std;

const int MAX_VALUE = 4000000;

int main()
{
	int previous = 1;
	int current = 2;
	int sum = 0;
	int temp;
	while (current <= MAX_VALUE)
	{
		if (current % 2 == 0)
		{
			sum += current;
		}
		temp = current;
		current += previous;
		previous = temp;
	}
	cout << sum << endl;
}