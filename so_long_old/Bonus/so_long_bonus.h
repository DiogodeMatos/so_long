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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./../libft/libft.h"
# include "./../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
	int		collectible;
	int		wall;
	int		player;
	int		exit;
	int		enemy;
	char	*counter;
	int		width;
	int		height;
	int		px;
	int		py;
	int		cc;
	int		ec;
	int		exitx;
	int		exity;
	char	**map;
	char	**map_check;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*collectible1_img;
	void	*collectible2_img;
	void	*collectible3_img;
	void	*enemy_img;
	void	*exit_img;
	void	*exitwin_img;
	int		hei;
	int		wid;
	void	*mlx;
	void	*mlx_win;
	int		size;
	int		moves;
}								t_map;

int		ft_checkmap(char **argv, t_map *map);
int		ft_check(char **argv, t_map *map);
int		ft_checkmap2(t_map *map);
int		ft_checkmap3(t_map *map);
int		ft_startgame(t_map *map);
void	ft_freemap(t_map *map);
int		ft_checkmove(t_map *map, int keysym, int x, int y);
int		ft_game_destroy(t_map *map);
void	ft_movew(t_map *map);
void	ft_moves(t_map *map);
void	ft_movea(t_map *map);
void	ft_moved(t_map *map);
int 	ft_animations(t_map *map);

#endif
