/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:57:46 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 17:58:50 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_frame(t_game *game)
{
	if (game->enemy_frame <= FRAME1)
		game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
				&game->width, &game->height);
	if (game->enemy_frame <= FRAME2 && game->enemy_frame >= FRAME1)
		game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy2.xpm",
				&game->width, &game->height);
	if (game->enemy_frame <= FRAME3 && game->enemy_frame >= FRAME2)
		game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy3.xpm",
				&game->width, &game->height);
	if (game->enemy_frame == FRAME3 + 30)
		game->enemy_frame = 1;
}

void	print_frame(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->enemy_frame++;
	game->x = 0;
	choose_frame(game);
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->y = 0;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'S')
				mlx_put_image_to_window(game->mlx, game->win, game->img_enemy,
					game->y, game->x);
			game->y += 64;
		}
		game->x += 64;
	}
	choose_frame(game);
}

int	animation_loop(t_game *game)
{
	horizontal(game);
	print_frame(game);
	return (0);
}
