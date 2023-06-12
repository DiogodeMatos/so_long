/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startgame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:49:45 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/19 09:50:52 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	print_map(t_map *map)
{
	int	i;
	int	j;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width+1)
		{
			ft_printf("%c", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}*/

void	ft_showimg(t_map *map)
{
	int	i;
	int	j;
	char element;
	
	i = -1;
	while(++i < map->height)
	{
		j = -1;
		while (++j < (map->width + 1))
		{
			element = map->map[i][j];
			if ( map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall_img, j * map->size, i * map->size);
			else if ( map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, j * map->size, i * map->size);
			else if ( map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, j * map->size, i * map->size);
			else if ( map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->collectible_img, j * map->size, i * map->size);
			else if ( map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit_img, j * map->size, i * map->size);
		}
	}
}

int	ft_game_destroy(t_map *map)
{
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->player_img);
	mlx_destroy_image(map->mlx, map->collectible_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_freemap(map);
	exit(0);
}

int	ft_keypress(int keysym, t_map *map)
{
	if (keysym == 65307)
		ft_game_destroy(map);
	if (keysym == 119) 	// W
		ft_checkmove(map, keysym, map->px, map->py - 1);
	if (keysym == 115) 	// S
		ft_checkmove(map, keysym, map->px, map->py + 1);
	if (keysym == 97) 	// A
		ft_checkmove(map, keysym, map->px - 1, map->py);
	if (keysym == 100) 	// D
		ft_checkmove(map, keysym, map->px + 1, map->py);
	return (0);
}

int ft_startgame(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, ((map->width + 1) * map->size), (map->height * map->size), "Monopoly");
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "./images/wall4.xpm", &map->wid, &map->hei);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, "./images/empty.xpm", &map->wid, &map->hei);
	map->player_img = mlx_xpm_file_to_image(map->mlx, "./images/smile.xpm", &map->wid, &map->hei);
	map->collectible_img = mlx_xpm_file_to_image(map->mlx, "./images/sun.xpm", &map->wid, &map->hei);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "./images/exit1.xpm", &map->wid, &map->hei);
	if (map->wall_img == NULL)
	{
		exit(EXIT_FAILURE);
	}
	//print_map(map);
	ft_showimg(map);
	mlx_hook(map->mlx_win, KeyPress, KeyPressMask, &ft_keypress, map);
	mlx_hook(map->mlx_win, DestroyNotify, ButtonPressMask, &ft_game_destroy, map);
	mlx_loop(map->mlx);
	return (0);
}
