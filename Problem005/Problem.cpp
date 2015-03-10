#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int gcd(long long a, long long b);
int lcm(long long a, long long b);

const int RANGE_MIN = 1;
const int RANGE_MAX = 20;

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	long long currentLcm = 1;
	for (int j = RANGE_MIN; j <= RANGE_MAX; ++j)
	{
		currentLcm = lcm(currentLcm, j);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto dur = duration_cast<milliseconds>(t2 - t1).count() / 1000.0f;
	cout << currentLcm << endl;
	cout << dur << endl;
}

int gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}