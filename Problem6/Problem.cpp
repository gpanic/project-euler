#include <iostream>
using namespace std;

int squareOfSum(int n);
int sumOfSquares(int n);

const int MAX_NUMBER = 100;

int main()
{
	cout << squareOfSum(MAX_NUMBER) - sumOfSquares(MAX_NUMBER) << endl;
}

int squareOfSum(int n)
{
	int sum = n * (n + 1) / 2;
	return sum * sum;
}

int sumOfSquares(int n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}