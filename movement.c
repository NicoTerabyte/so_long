/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:46:08 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/14 16:24:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./img/idle_up.xpm",
			&game->width, &game->height);
	if (basic_check_wall_up(game) == 0)
		return (0);
	if (game->map[game->player_stats.x - 1][game->player_stats.y] == EMPTY)
		check_empty_up(game);
	else if (game->map[game->player_stats.x - 1][game->player_stats.y] ==
		COLLECTIBLE)
	{
		check_collect_up(game);
	}
	else if (game->map[game->player_stats.x - 1][game->player_stats.y] ==
		EXIT && game->collect == 0)
	{
		check_exit_up(game);
	}
	else if (game->map[game->player_stats.x - 1][game->player_stats.y] ==
			ENEMY_S)
	{
		check_death(game);
	}
	return (1);
}

int	left(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./img/idle_left.xpm",
			&game->width, &game->height);
	if (basic_check_wall_left(game) == 0)
		return (0);
	if (game->map[game->player_stats.x][game->player_stats.y - 1] == EMPTY)
		check_empty_left(game);
	else if (game->map[game->player_stats.x][game->player_stats.y - 1] ==
		COLLECTIBLE)
	{
		check_collect_left(game);
	}
	else if (game->map[game->player_stats.x][game->player_stats.y - 1] ==
		EXIT && game->collect == 0)
	{
		check_exit_left(game);
	}
	else if (game->map[game->player_stats.x][game->player_stats.y - 1] ==
			ENEMY_S)
	{
		check_death(game);
	}
	return (1);
}

int	down(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./img/idle.xpm",
			&game->width, &game->height);
	if (basic_check_wall_down(game) == 0)
		return (0);
	if (game->map[game->player_stats.x + 1][game->player_stats.y] == EMPTY)
		check_empty_down(game);
	else if (game->map[game->player_stats.x + 1][game->player_stats.y] ==
		COLLECTIBLE)
	{
		check_collect_down(game);
	}
	else if (game->map[game->player_stats.x + 1][game->player_stats.y] ==
		EXIT && game->collect == 0)
	{
		check_exit_down(game);
	}
	else if (game->map[game->player_stats.x + 1][game->player_stats.y] ==
			ENEMY_S)
	{
		check_death(game);
	}
	return (1);
}

int	right(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./img/idle_right.xpm",
			&game->width, &game->height);
	if (basic_check_wall_right(game) == 0)
		return (0);
	if (game->map[game->player_stats.x][game->player_stats.y + 1] == EMPTY)
		check_empty_right(game);
	else if (game->map[game->player_stats.x][game->player_stats.y + 1] ==
		COLLECTIBLE)
	{
		check_collect_right(game);
	}
	else if (game->map[game->player_stats.x][game->player_stats.y + 1] ==
		EXIT && game->collect == 0)
	{
		check_exit_right(game);
	}
	else if (game->map[game->player_stats.x][game->player_stats.y + 1] ==
			ENEMY_S)
	{
		check_death(game);
	}
	return (1);
}

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->mv_count);
	mlx_string_put(game->mlx, game->win, 10, 16, 16777215, "-------");
	mlx_string_put(game->mlx, game->win, 10, 32, 16777215, "|MOVES| ");
	mlx_string_put(game->mlx, game->win, 10, 48, 16777215, "-------");
	mlx_string_put(game->mlx, game->win, game->width + 32, 32, 16777215, str);
	free(str);
}
