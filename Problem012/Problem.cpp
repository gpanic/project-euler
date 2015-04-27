#include <iostream>
using namespace std;

const int MAX_DIVISORS = 500;

int number_of_divisors(int n);

int main()
{
	int current_value = 1;
	int current_index = 1;
	while (number_of_divisors(current_value) <= MAX_DIVISORS)
	{
		++current_index;
		current_value += current_index;
	}
	cout << current_value << endl;
	cin.get();
}

int number_of_divisors(int n)
{
	int num = 0;
	int square_root = static_cast<int>(sqrt(n));
	for (int i = 1; i <= square_root; ++i)
	{
		if (n % i == 0)
		{
			num += 2;
		}
	}
	if (n == square_root)
	{
		--num;
	}
	return num;
}