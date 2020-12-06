/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:29:56 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:44:02 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"
#include "ft_utils.h"

int		is_valid_grid(int *grid, int n)
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
** directions:
** 	0. (default value) standard matrix position (row x, column y)
** 	1. vertical reflection
** 	2. 90 deg right rotation + horizontal reflection
** 	3. 90 deg right rotation
*/

int		get_coordinates(int x, int y, int direction)
{
	if (direction == 1)
		return (x + 4 * (4 - 1 - y));
	if (direction == 2)
		return (y + 4 * x);
	if (direction == 3)
		return (4 - 1 - y + 4 * x);
	return (x + 4 * y);
}

int		side_conditions_respected(
		int *grid, int *side_conditions, int direction)
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
			val = grid[get_coordinates(i, j++, direction)];
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

int		conditions_respected(int *grid, int *conditions)
{
	return (side_conditions_respected(grid, conditions, 0)
		&& side_conditions_respected(grid, conditions + 4, 1)
		&& side_conditions_respected(grid, conditions + 4 * 2, 2)
		&& side_conditions_respected(grid, conditions + 4 * 3, 3));
}

int		add_item(int *conditions, int *grid, int n)
{
	int i;

	if (!is_valid_grid(grid, n - 1))
		return (0);
	if (n >= 4 * 4)
	{
		if (conditions_respected(grid, conditions))
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
		if (add_item(conditions, grid, n + 1))
			return (1);
		i++;
	}
	return (0);
}
