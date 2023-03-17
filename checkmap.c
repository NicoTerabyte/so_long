/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:55 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 18:27:56 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangular(t_game *game)
{
	int	ref;
	int	i;

	i = 0;
	ref = ft_strlen(game->map[0]);
	while (game->map[i] != 0)
	{
		if (ref != (int) ft_strlen(game->map[i]))
		{
			ft_printf("Error\n the lenght of the map is not respected\n");
			free_map(game);
			exit(1);
		}
		i++;
	}
	return (1);
}

static void	check_w_lines(t_game *game, int i, int j)
{
	while (game->map[i])
		i++;
	j = 0;
	while (game->map[0][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i -1][j] != '1')
		{
			ft_printf("Error\n the walls are not setted correctly\n");
			free_map(game);
			exit(1);
		}
		j++;
	}
}

int	wall(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	check_w_lines(game, i, j);
	i = 1;
	j = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (game->map[i][j] != '1' || game->map[i][len -1] != '1')
		{
			ft_printf("Error\n the wall is not placed correctly\n");
			free_map(game);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	check_things(t_game *game)
{
	checker_n_tile(game);
	if (game->tile.p == 0 || game->tile.c == 0 || game->tile.e == 0
		|| game->tile.empty == 0)
	{
		ft_printf("Error\n one of the tile is missing\n");
		free_map(game);
		exit(1);
	}
	game->collect = game->tile.c;
	return (1);
}

void	check_all(t_game *game)
{
	rectangular(game);
	wall(game);
	check_things(game);
	check_not_tile(game);
}
