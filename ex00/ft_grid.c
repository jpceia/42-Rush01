#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_valid_grid(int grid[4][4], int n)
{
	int i;
	int x;
	int y;
	int val;

	x = n / 4;
	y = n % 4;
	val = grid[x][y];
	i = 0;
	while (i < x)
		if (val == grid[i++][y])
			return (0);
	i = 0;
	while (i < y)
		if (val == grid[x][i++])
			return (0);
	return (1);
}

int add_item(int grid[4][4], int n)
{
	int i;
	int sum;
	if (!is_valid_grid(grid, n - 1))
		return (0);
	if (n >= 16)
		return (1);
	sum = 0;
	i = 0;
	while (i < 4)
	{
		grid[n / 4][n % 4] = i + 1;
		sum += add_item(grid, n + 1);
		i++;
	}
	return (sum);
}

int main(void)
{
	int grid[4][4];
	printf("Possible combinations: %d", add_item(grid, 0));
	return (0);
}
