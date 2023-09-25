/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:52:18 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/26 00:13:28 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countobjects()
{
	int	i;
	int	j;

	i = -1;
	while (map()->map[++i])
	{
		j = -1;
		while (map()->map[i][++j])
		{
			if (map()->map[i][j] != '1' && map()->map[i][j] != '0' && map()->map[i][j] != 'C'
				&& map()->map[i][j] != 'E' && map()->map[i][j] != 'P' && map()->map[i][j] != '\n')
				return (ft_printf("%s", "Error\nInvalid object in map\n"));
			if (map()->map[i][j] == 'C')
				map()->collectible++;
			else if (map()->map[i][j] == 'E')
				map()->exit++;
			else if (map()->map[i][j] == 'P')
				map()->player++;
		}
	}
	return (0);
}

int	ft_checkwalls(void)
{
	static int	i;
	static int	j;

	while (j <= map()->width)
	{
		if (map()->map[0][j] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		if (map()->map[map()->height -1][j] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		j++;
	}
	while (i < map()->height - 1)
	{
		if (map()->map[i][0] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		if (map()->map[i][map()->width] != '1')
			return (ft_printf("%s", "Error\nMap isn't surrounded by walls\n"));
		i++;
	}
	return (1);
}

int	ft_checkobjects(void)
{
	if (map()->collectible < 1)
		return (ft_printf("%s", "Error\nNo collectibles\n"));
	if (map()->exit != 1)
		return (ft_printf("%s", "Error\nNo exit or many exits\n"));
	if (map()->player != 1)
		return (ft_printf("%s", "Error\nNo player or many players\n"));
	if (ft_checkwalls() != 1)
		return (0);
	return (1);
}

int	ft_checkwidth(void)
{
	int	i;
	int	j;
	int	width;

	i = -1;
	while (map()->map[++i])
	{
		j = -1;
		while (map()->map[i][++j])
		printf("i = %d, j = %d\n", i, j);
		if (i == 0)
			width = j;
		else if (j != width)
		{
			if (j == width - 1)
				if (i == map()->height - 1)
					return (1);
			return (ft_printf("%s", "Error\nMap isn't rectangular\n"));
		}
	}
	return (ft_printf("%s", "Error\nMap isn't rectangular\n"));
	//return (1);
}

int	ft_checkmap2(void)
{
	if (ft_countobjects())
		return (0);
	if ((ft_checkwidth() != 1))// || (ft_checkobjects() != 1))
		return (0);
	return (1);
}
