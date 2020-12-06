#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(int *grid)
{
	int i;

	i = 0;
	while(i < 4)
	{
		ft_putchar('0' + grid[i * 4]);
		ft_putchar(' ');
		ft_putchar('0' + grid[i * 4 + 1]);
		ft_putchar(' ');
		ft_putchar('0' + grid[i * 4 + 2]);
		ft_putchar(' ');
		ft_putchar('0' + grid[i * 4 + 3]);
		ft_putchar('\n');
		i++;
	}
}

int is_valid_grid(int *grid, int n)
{
	int i;
	int x;
	int y;
	int val;

	x = n / 4;
	y = n % 4;
	val = grid[n];
	i = 0;
	while (i < x)
		if (val == grid[y + 4 * i++])
			return (0);
	i = 0;
	while (i < y)
		if (val == grid[4 * x + i++])
			return (0);
	return (1);
}

int add_item(int *grid, int n)
{
	int i;
	int sum;
	if (!is_valid_grid(grid, n - 1))
		return (0);
	if (n >= 16)
	{
		ft_print_grid(grid);
		ft_putchar('\n');
		return (1);
	}
	sum = 0;
	i = 0;
	while (i < 4)
	{
		grid[n] = i + 1;
		sum += add_item(grid, n + 1);
		i++;
	}
	return (sum);
}

int main(void)
{
	int grid[16];
	printf("Possible combinations: %d\n", add_item(grid, 0));
	return (0);
}
