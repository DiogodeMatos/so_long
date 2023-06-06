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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	print_map(t_map *map)
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
}

int ft_startgame(t_map *map)
{
    void	*mlx;
	void	*mlx_win;
	int	i;
	int	j;
	int	rx;
	int	ry;
	char element;

    mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (map->width * 64), (map->height * 64), "Monopoly");
	map->wall_img = mlx_xpm_file_to_image(mlx, "./images/wall4.xpm", &map->wid, &map->hei);
	//map->floor_img = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &map->wid, &map->hei);
	map->player_img = mlx_xpm_file_to_image(mlx, "./images/smile.xpm", &map->wid, &map->hei);
	map->collectible_img = mlx_xpm_file_to_image(mlx, "./images/sun.xpm", &map->wid, &map->hei);
	map->exit_img = mlx_xpm_file_to_image(mlx, "./images/exit1.xpm", &map->wid, &map->hei);
	if (map->wall_img == NULL)
	{
		exit(EXIT_FAILURE);
	}
	print_map(map);
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			rx = j * 64;
			ry = i * 64;

			element = map->map[i][j];
			if ( map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map->wall_img, rx, ry);
			//else if ( map->map[i][j] == '0')
				//mlx_put_image_to_window(mlx, mlx_win, map->floor_img, rx, ry);
			else if ( map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, map->player_img, rx, ry);
			else if ( map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, map->collectible_img, rx, ry);
			else if ( map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map->exit_img, rx, ry);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
    return (0);
}