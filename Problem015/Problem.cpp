#define ull unsigned long long
#include <iostream>

const int GRID_SIZE = 20;

int main()
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
	std::cin.get();
}