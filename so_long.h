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
	int	collectible;				// coletavel	
	int	wall;					// parede
	int	player;				// jogador
	int	exit;				// saida
	//int	space;			// espaco vazio
	int	width;
	int	height;
	int	px;
	int	py;
	int	cc;
	int	ec;
	char	**map;
	char	**map_check;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	int		hei;
	int		wid;
	void	*mlx;
	void	*mlx_win;
}								t_map;

int	ft_checkmap(char **argv, t_map *map);
int ft_check(char **argv, t_map *map);
int	ft_checkmap2(t_map *map);
int	ft_checkmap3(t_map *map);
int	ft_startgame(t_map *map);

# endif
