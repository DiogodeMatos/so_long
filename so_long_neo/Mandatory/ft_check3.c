/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/26 16:24:37 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkpath(int x, int y)
{
	if (map()->map_copy[y][x] == '1' || map()->map_copy[y][x] == 'X')
		return (1);
	if (map()->map_copy[y][x] == 'C')
		map()->cc++;
	if (map()->map_copy[y][x] == 'E')
	{
		if (map()->cc == map()->collectible)
			map()->ec++;
		return (0);
	}
	map()->map_copy[y][x] = 'X';
	ft_checkpath(x + 1, y);
	ft_checkpath(x - 1, y);
	ft_checkpath(x, y + 1);
	ft_checkpath(x, y - 1);
	return (0);
}

void	ft_checkppos(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map()->height)
	{
		x = -1;
		while (++x < map()->width)
		{
			if (map()->map[y][x] == 'P')
			{
				map()->px = x;
				map()->py = y;
			}
			if (map()->map[y][x] == 'E')
			{
				map()->exitx = x;
				map()->exity = y;
			}
		}
	}
}
