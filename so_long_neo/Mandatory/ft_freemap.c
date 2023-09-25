/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:54:46 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/09/25 22:56:10 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(void)
{
	int	i;

	i = 0;
	while (i < map()->height)
	{
		if (map()->map)
			free(map()->map[i]);
		if (map()->map_check)
			free(map()->map_check[i]);
		i++;
	}
	free(map()->map);
	if (map()->map_check)
		free(map()->map_check);
}
