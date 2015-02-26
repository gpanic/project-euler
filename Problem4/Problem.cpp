#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int MAX_NUMBER = 999;

bool palindrome(long long);
bool palindrome2(long long);

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	int max = -1;
	for (int i = MAX_NUMBER; i > 99; --i)
	{
		for (int j = MAX_NUMBER; j > 99; --j)
		{
			long long product = i * j;
			if (palindrome(product) && product > max)
				max = product;
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	cout << max << endl;
	auto dur = duration_cast<milliseconds>(t2 - t1).count() / 1000.0f;
	cout << dur << endl;

	return 0;
}

bool palindrome(long long num)
{
	int i = num;
	int rev = 0;
	while (i > 0)
	{
		int digit = i % 10;
		rev = rev * 10 + digit;
		i /= 10;
	}
	return rev == num;
}

bool palindrome2(long long num)
{
	string str = to_string(num);
	bool result = true;
	for (int i = 0; i < str.length() / 2; ++i)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			result = false;
		}
	}
	return result;
}