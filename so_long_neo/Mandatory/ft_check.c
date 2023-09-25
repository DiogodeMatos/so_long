/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/25 23:37:35 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map(char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map()->map = malloc(sizeof(char *) * (map()->height + 1));
	if (!map()->map)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map()->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map()->map[i] = NULL;
	close(fd);
	return (map()->map);
}

char	**ft_mapcheck(char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map()->map_check = malloc(sizeof(char *) * (map()->height + 1));
	if (!map()->map_check)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map()->map_check[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map()->map_check[i] = NULL;
	close(fd);
	return (map()->map_check);
}

int	ft_checkmap(char **argv)
{
	int		fd;
	char	*line;
	static int		j;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s", "Error\nInvalid file\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			map()->width = ft_strlen(line) - 1;
		else
			map()->width = ft_strlen(line);
		if (map()->width == 0)
			j = 1;
		map()->height++;
		printf("%d\n", map()->height);
		free(line);
	}
	close(fd);
	return (j);
}

int	ft_check(char **argv)
{
	int	i;

	i = ft_checkmap(argv);
	if (i == 0)
	{
		map()->map = ft_map(argv);
		map()->map_check = ft_mapcheck(argv);
		if (ft_checkmap2() == 1)
		{
			// if (ft_checkmap3() == 1)
				return (1);
		}
	}
	if (i == 2)
		ft_printf("%s", "Error\nInvalid object in map\n");
	return (0);
}
