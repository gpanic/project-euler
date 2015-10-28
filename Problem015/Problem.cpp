#include <iostream>

typedef unsigned long long ull;

const int GRID_SIZE = 20;

void lattice_paths1();
void lattice_paths2();
ull combinations(int n, int k);

int main()
{
	lattice_paths1();
	lattice_paths2();
	std::cin.get();
}

void lattice_paths1()
{
	ull grid[GRID_SIZE + 1][GRID_SIZE + 1] = { 0 };

	for (int i = 0; i < GRID_SIZE; ++i)
	{
		grid[i][GRID_SIZE] = 1;
		grid[GRID_SIZE][i] = 1;
	}

	for (int i = GRID_SIZE - 1; i >= 0; --i)
	{
		for (int j = GRID_SIZE - 1; j >= 0; --j)
		{
			grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
		}
	}
	std::cout << grid[0][0] << std::endl;
}

void lattice_paths2()
{
	std::cout << combinations(2 * GRID_SIZE, GRID_SIZE) << std::endl;
}

ull combinations(int n, int k)
{
	ull combs = 1;
	for (int i = 1; i <= k; ++i)
	{
		combs *= n + 1 - i;
		combs /= i;
	}
	return combs;
}