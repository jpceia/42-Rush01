/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:01:19 by jceia             #+#    #+#             */
/*   Updated: 2020/12/05 17:44:33 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	***combinations;

// 2
combinations[0] = {
	{4, 1, 2, 3},
	{4, 1, 3, 2},
	{4, 2, 1, 3},
	{4, 2, 3, 1},
	{4, 3, 1, 2},
	{4, 3, 2, 1},
	0
}

combinations[1] = {
	{1, 4, 2, 3},
	{1, 4, 3, 2},
	{2, 4, 1, 3},
	{2, 4, 3, 1},
	{3, 4, 1, 2},
	{3, 4, 2, 1},
	
	{3, 2, 4, 1},
	{3, 1, 4, 3},
	{2, 1, 4, 3},

	{3, 2, 1, 4},
	{3, 1, 2, 4},
	0
}

combinations[2] = {
	{1, 3, 4, 2},
	{1, 2, 4, 3},
	{2, 3, 4, 1},
	{1, 3, 2, 4},
	{2, 3, 1, 4},
	{2, 1, 3, 4},
	0
}

combinations[3] = {
	{1, 2, 3, 4},
	0
}

voif	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_valid_line(int *row, int n)
{
	int	i;
	int	*comb_n;

	comb_n = combinations[n - 1];
	while (*comb_n)
	{
		i = 0;
		while (i < 4 && *comb_n[i] == row[i])
			i++;
		if (i == 4)
			return (1);
		comb_n++;
	}
	return (0);
}

int	is_valid(int **grid, int **input)
{
	int 	i;
	int		j;
	int 	row[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			row[j] = grid[i][3 - j++];
		if (!is_valid_line(row, input[1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			row[j] = grid[j++][i];
		if (!is_valid_line(row, input[2][i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			row[j] = grid[3 - j++][i];
		if (!is_valid_line(row, input[3][i]))
			return (0);
		i++;
	}
	
	return (1);
}

void	show_grid(int** grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			ft_putchar('0' + grid[j++][i]);
		ft_putchar('\n');
		i++;
	}
}

void	get_input(int **input, char *s)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			input[i][j] = (int)(s[2 * (i + 4 * j)] - '0');
			j++;
		}
		i++;
	}
}

int	main(int argc, char** argv)
{

	iint	input[4][4];
	int grid[4][4];

	get_input(input, argv[1]);

	if (input == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	while (*combinations[input[0][0]] != 0)
	{
		grid[0] = *combinations[input[0][1]];
		while (*combinations[input[0][1]] != 0)
		{
			grid[1] = *combinations[input[0][1]];
			while (*combinations[input[0][2]] != 0)
			{
				grid[2] = *combinations[input[0][2]]
				while (*combinations[input[0][3]] != 0)
				{
					grid[3] = *combinations[input[0][3]];

					if (is_valid(grid, input))
					{
						show_grid(grid);
						return (0);
					}

					combinations[input[0][3]]++;
				}
				combinations[input[0][2]]++;
			}
			combinations[input[0][1]]++;
		}
		combinations[input[0][0]]++;
	}
	write(1, "Error\n", 6);
}
