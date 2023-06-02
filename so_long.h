/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:33 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/10 11:15:36 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
	int	collectible;
	int	wall;
	int	player;
	int	exit;
	int	space;
	int	width;
	int	height;
	int	px;
	int	py;
	int	cc;
	int	ec;
	char	**map;
	void	*wall_img;
	int		hei;
	int		wid;
}								t_map;

int	ft_checkmap(char **argv, t_map *map);
int ft_check(char **argv, t_map *map);
int	ft_checkmap2(t_map *map);
int	ft_checkmap3(t_map *map);
int	ft_startgame(t_map *map);

# endif
