/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:26:42 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/16 19:12:59 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int  ft_animations(t_map *map)
{
  int i;
  int j;

  i = -1;
	// while (++i < map->height)
	// {
	// 	j = -1;
	// 	while (++j < (map->width + 1))
	// 	{
	// 		if (map->map[i][j] == 'C')
	// 		{
  //       mlx_put_image_to_window(map->mlx, map->mlx_win,
	// 		map->collectible1_img, j * map->size, i * map->size);
  //     }
	// 	}
	// }
  if (map->moves % 4 == 0)
  {
    while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			if (map->map[i][j] == 'C')
			{
        mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible1_img, j * map->size, i * map->size);
      }
		}
	}
  }
  else if (map->moves % 3 == 0)
  {
    while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			if (map->map[i][j] == 'C')
			{
        mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible2_img, j * map->size, i * map->size);
      }
		}
	}
  }
  else if (map->moves % 2 == 0)
  {
    while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			if (map->map[i][j] == 'C')
			{
        mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible3_img, j * map->size, i * map->size);
      }
		}
	}
  }
  else
  {
    while (++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			if (map->map[i][j] == 'C')
			{
        mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible_img, j * map->size, i * map->size);
      }
		}
	}
  }
  return (1);
}
