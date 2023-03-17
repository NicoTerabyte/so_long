/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:21:42 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 19:17:54 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <mlx.h>
# include "libftmio/libft.h"
# include "ft_printfmio/ft_printf.h"
# define FRAME1 15
# define FRAME2 30
# define FRAME3 50

typedef enum s_tiletype
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	ENEMY_S = 'S'
}	t_tiletype;

typedef struct s_tile_c
{
	int	c;
	int	e;
	int	p;
	int	empty;
}	t_tile_c;

typedef struct s_player
{
	void		*idle;
	int			x;
	int			y;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		mv;
	int		num_enemy;
}	t_enemy;

typedef struct s_collect
{
	int		n_collect;
	void	*current_img;
}	t_collect_img;

typedef struct s_panel
{
	int	strcd;
}	t_panel;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img_0;
	void		*img_wall;
	void		*img_exit;
	void		*img_collect;
	void		*img_enemy;
	void		*img_player;
	int			collect;
	t_player	player_stats;
	t_enemy		enemy;
	t_enemy		enemy_static;
	t_panel		panel;
	t_tile_c	tile;
	char		*path;
	int			width;
	int			height;
	char		**map;
	int			mv_count;
	int			pl_x;
	int			pl_y;
	int			no_collect;
	int			start;
	int			enemy_kill;
	int			enemy_num;
	int			enemy_frame;
	int			x;
	int			y;
}	t_game;

void	check_all(t_game *game);
char	**read_map(char *file, t_game *game);
int		draw_map(t_game *game);
int		key_pressed(int keycode, t_game *key);
int		close_game(t_game *game);

int		up(t_game *game);
int		down(t_game *game);
int		left(t_game *game);
int		right(t_game *game);

void	game_set(t_game *game);
void	set_window(t_game *game);
void	set_wcp(t_game *game, int riga, int colonna);
void	set_eenem(t_game *game, int riga, int colonna);

void	check_img(t_game *game);
int		horizontal(t_game *game);
void	check_death(t_game *game);
void	display_moves(t_game *game);
void	checker_n_tile(t_game *game);

void	check_movement_enemyh_plus(t_game *game);
void	check_movement_enemyh_minus(t_game *game);

int		basic_check_wall_up(t_game *game);
void	check_empty_up(t_game *game);
void	check_collect_up(t_game *game);
void	check_exit_up(t_game *game);
int		basic_check_wall_left(t_game *game);
void	check_empty_left(t_game *game);
void	check_collect_left(t_game *game);
void	check_exit_left(t_game *game);
int		basic_check_wall_down(t_game *game);
void	check_empty_down(t_game *game);
void	check_collect_down(t_game *game);
void	check_exit_down(t_game *game);

int		basic_check_wall_right(t_game *game);
void	check_empty_right(t_game *game);
void	check_collect_right(t_game *game);
void	check_exit_right(t_game *game);
void	free_map(t_game *game);
void	check_not_tile(t_game *game);
void	choose_frame(t_game *game);
int		animation_loop(t_game *game);
#endif
