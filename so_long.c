/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/03 10:46:42 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_checkber(char **argv)
{
	static int	a;
	char	*str;
	int	b;

	str = ".ber";
	while (argv[1][a])
	{
		b = 0;
		while (argv[1][a] == str[b])
		{
				a++;
				b++;
				if (argv[1][a] == '\0' && str[b] == '\0')
					return (1);
				else if ((argv[1][a] == '\0' && str[b] != '\0') || (argv[1][a] != '\0' && str[b] == '\0'))
					a--;
		}
		a++;
	}
	ft_printf("%s", "Error\nInvalid file extension\n");
	return (0);
}

void setup_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player = 0;
	map->space = 0;
	map->collectible = 0;
	map->exit= 0;
	map->wall = 0;
	map->px = 0;
	map->py = 0;
	map->ec = 0;
	map->cc = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	static int i;

	if (argc != 2)
		return (ft_printf("%s", "Error\nInvalid number of arguments\n"));
	if (ft_checkber(argv) == 0)
		return (0);
	setup_map(&map);
	ft_check(argv, &map);
	while (i < map.height)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	return (0);
}

/*int	main()
{
	ft_printf("so_long");
}*/
