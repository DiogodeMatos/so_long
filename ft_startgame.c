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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	//mlx_win = mlx_new_window(mlx, (map->width * 32), (map->height * 32), "Monopoly");
	mlx_win = mlx_new_window(mlx, 500, 500, "Monopoly");
	printf("%s", "gfd");
	map->wall_img = mlx_xpm_file_to_image(mlx, "./images/ramen.xpm", &map->wid, &map->hei);
	map->player_img = mlx_xpm_file_to_image(mlx, "./images/ramen.xpm", &map->wid, &map->hei);
	if (map->wall_img == NULL)
	{
		exit(EXIT_FAILURE);
	}
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			rx = j * 32;
			ry = i * 32;

			element = map->map[i][j];
			if (element == '1')
				mlx_put_image_to_window(mlx, mlx_win, map->wall_img, rx, ry);
			else if (element == 'P')
				mlx_put_image_to_window(mlx, mlx_win, map->player_img, rx, ry);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
    return (0);
}