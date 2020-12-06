/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 06:50:44 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:31:03 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_algo.h"

int		parse_args(int *conditions, char *str)
{
	int index;
	int i;

	if (ft_strlen(str) != 16 * 2 - 1)
		return (0);
	index = 0;
	while (index < 16)
	{
		i = str[2 * index] - '0';
		if (i < 1 || i > 4)
			return (0);
		conditions[index] = i;
		index++;
	}
	return (1);
}

int		main(int argc, char **argv)
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
