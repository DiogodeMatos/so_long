/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:21:55 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/06/12 12:21:57 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_move(t_map *map, char a)
{
    if (a == 'w')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, map->px * map->size, map->py * map->size);
        map->map[map->py][map->px] = '0';
        map->py--;
        if (map->map[map->py][map->px] == 'C')
            map->collectible--;
        if (map->map[map->py][map->px] == 'E')
            ft_game_destroy(map);
        map->map[map->py][map->px] = 'P';
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, map->px * map->size, map->py * map->size);
    }
    else if (a == 's')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, map->px * map->size, map->py * map->size);
        map->map[map->py][map->px] = '0';
        map->py++;
        if (map->map[map->py][map->px] == 'C')
            map->collectible--;
        if (map->map[map->py][map->px] == 'E')
            ft_game_destroy(map);
        map->map[map->py][map->px] = 'P';
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, map->px * map->size, map->py * map->size);
    }
}

void    ft_move2(t_map *map, char a)
{
    if (a == 'a')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, map->px * map->size, map->py * map->size);
        map->map[map->py][map->px] = '0';
        map->px--;
        if (map->map[map->py][map->px] == 'C')
            map->collectible--;
        if (map->map[map->py][map->px] == 'E')
            ft_game_destroy(map);
        map->map[map->py][map->px] = 'P';
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, map->px * map->size, map->py * map->size);
    }
    else if (a == 'd')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img, map->px * map->size, map->py * map->size);
        map->map[map->py][map->px] = '0';
        map->px++;
        if (map->map[map->py][map->px] == 'C')
            map->collectible--;
        if (map->map[map->py][map->px] == 'E')
            ft_game_destroy(map);
        map->map[map->py][map->px] = 'P';
        mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img, map->px * map->size, map->py * map->size);
    }
}

int ft_checkmove(t_map *map, char a, int x, int y)
{
    if (map->map[y][x] == '1')
        return (0);
    if (map->map[y][x] == 'E' && map->collectible != 0)
        return (0);
    if ((a == 'w') || (a == 's'))
        ft_move(map, a);
    if ((a == 'a') || (a == 'd'))
        ft_move2(map, a);
    return (1);
}
