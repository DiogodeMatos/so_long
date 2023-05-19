/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/19 09:08:36 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkpath(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == 'X')
		return (1);
	if (map->map[y][x] == 'E')
		map->ec++;
	if (map->map[y][x] == 'C')
		map->cc++;
	map->map[y][x] = 'X';
	ft_checkpath(map, x + 1, y);
	ft_checkpath(map, x - 1, y);
	ft_checkpath(map, x, y + 1);
	ft_checkpath(map, x, y - 1);
	return (0);
}

void	ft_checkppos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height -1)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				map->px = x;
				map->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int ft_checkmap3(t_map *map)
{
	ft_checkppos(map);
	ft_printf("px = %d\n", map->px);
	ft_printf("py = %d\n", map->py);
	ft_checkpath(map, map->px, map->py);
	ft_printf("Porto\n");
	if (map->ec == 1 || map->cc == map->collectible)
		return (1);
	return (ft_printf("%s", "Error\nInvalid Path\n"));
}
