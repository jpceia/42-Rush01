/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:07:31 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:21:42 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_print_grid(int *grid)
{
	int i;

	i = 0;
	while (i < 4)
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
