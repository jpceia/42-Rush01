/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:30:18 by jceia             #+#    #+#             */
/*   Updated: 2020/12/06 07:30:48 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H

int		is_valid_grid(int *grid, int n);

int		get_coordinates(int x, int y, int direction);

int		side_conditions_respected(
		int *grid, int *side_conditions, int direction);

int		conditions_respected(int *grid, int *conditions);

int		add_item(int *conditions, int *grid, int n);

#endif
