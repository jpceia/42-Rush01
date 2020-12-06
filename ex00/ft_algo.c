/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:29:56 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:56:53 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"
#include "ft_utils.h"

int		is_valid_grid(int *grid, int n, int size)
{
	int i;
	int x;
	int y;
	int val;

	x = n % size;
	y = n / size;
	val = grid[n];
	i = 0;
	while (i < x)
		if (val == grid[i++ + size * y])
			return (0);
	i = 0;
	while (i < y)
		if (val == grid[x + size * i++])
			return (0);
	return (1);
}

/*
** directions:
** 	0. (default value) standard matrix position (row x, column y)
** 	1. vertical reflection
** 	2. 90 deg right rotation + horizontal reflection
** 	3. 90 deg right rotation
*/

int		get_coordinates(int x, int y, int direction, int size)
{
	if (direction == 1)
		return (x + size * (size - 1 - y));
	if (direction == 2)
		return (y + size * x);
	if (direction == 3)
		return (size - 1 - y + size * x);
	return (x + size * y);
}

int		side_conditions_respected(
		int *grid, int *side_conditions, int direction, int size)
{
	int i;
	int j;
	int max_seen;
	int count_seen;
	int val;

	i = 0;
	while (i < size)
	{
		count_seen = 0;
		max_seen = 0;
		j = 0;
		while (j < size)
		{
			val = grid[get_coordinates(i, j++, direction, size)];
			if (val > max_seen)
			{
				count_seen++;
				max_seen = val;
			}
		}
		if (count_seen != side_conditions[i++])
			return (0);
	}
	return (1);
}

int		conditions_respected(int *grid, int *conditions, int size)
{
	return (side_conditions_respected(grid, conditions, 0, size)
		&& side_conditions_respected(grid, conditions + 1 * size, 1, size)
		&& side_conditions_respected(grid, conditions + 2 * size, 2, size)
		&& side_conditions_respected(grid, conditions + 3 * size, 3, size));
}

int		add_item(int *conditions, int *grid, int n, int size)
{
	int i;

	if (!is_valid_grid(grid, n - 1, size))
		return (0);
	if (n >= size * size)
	{
		if (conditions_respected(grid, conditions, size))
		{
			ft_print_grid(grid, size);
			return (1);
		}
		return (0);
	}
	i = 0;
	while (i < size)
	{
		grid[n] = i + 1;
		if (add_item(conditions, grid, n + 1, size))
			return (1);
		i++;
	}
	return (0);
}
