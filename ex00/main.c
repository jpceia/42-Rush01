#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while(str[index])
		index++;
	return (index);
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

	x = n % 4;
	y = n / 4;
	val = grid[n];
	i = 0;
	while (i < x)
		if (val == grid[i++ + 4 * y])
			return (0);
	i = 0;
	while (i < y)
		if (val == grid[x + 4 * i++])
			return (0);
	return (1);
}

/*
* directions:
* 	0. (default value) standard matrix position (row x, column y)
* 	1. vertical reflection
* 	2. 90 deg right rotation + horizontal reflection
* 	3. 90 deg right rotation
*/
int get_coordinates(int x, int y, int direction)
{
	if (direction == 1)
		return (x + 4 * (3 - y));
	if (direction == 2)
		return (y + 4 * x);
	if (direction == 3)
		return (3 - y + 4 * x);
	return (x + 4 * y);
}

int side_conditions_are_respected(int* grid, int* one_side_conditions, int direction)
{
	int i;
	int j;
	int max_seen;
	int count_seen;
	int val;

	i = 0;
	while (i < 4)
	{
		count_seen = 0;
		max_seen = 0;
		j = 0;
		while (j < 4)
		{
			val = grid[get_coordinates(i, j, direction)];
			if (val > max_seen)
			{
				count_seen++;
				max_seen = val;
			}
			j++;
		}
		if (count_seen != one_side_conditions[i])
			return (0);
		i++;
	}
	return (1);
}

int conditions_are_respected(int *grid, int* conditions)
{
	return (side_conditions_are_respected(grid, conditions, 0)
		&& side_conditions_are_respected(grid, conditions + 4, 1)
		&& side_conditions_are_respected(grid, conditions + 8, 2)
		&& side_conditions_are_respected(grid, conditions + 12, 3)
	);
}

int add_item(int *conditions, int *grid, int n)
{
	int i;
	if (!is_valid_grid(grid, n - 1))
		return (0);
	if (n >= 16)
	{
		if (conditions_are_respected(grid, conditions))
		{
			ft_print_grid(grid);
			return (1);
		}
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		grid[n] = i + 1;
		if(add_item(conditions, grid, n + 1))
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(int* conditions, char* str)
{
	int index;
	int i;

	if (ft_strlen(str) != 16 * 2 - 1)
		return (0);
	
	index = 0;
	while(index < 16)
	{
		i = str[2 * index] - '0';
		if (i < 1 || i > 4)
			return (0);
		conditions[index] = i;
		index++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int success;
	int grid[16];
	int conditions[16];

	success = 1;
	if (argc > 1)
		success &= parse_args(conditions, argv[1]);
	else
		success = 0;
	if (success)
		success = add_item(conditions, grid, 0);
	if (!success)
		ft_putstr("Error\n");
	return (0);
}
