/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:49:38 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 16:34:39 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nYou didn't put he map as an argument\n");
		exit(1);
	}
	game.map = read_map(argv[1], &game);
	game_set(&game);
	check_all(&game);
	game.mlx = mlx_init();
	set_window(&game);
	game.win = mlx_new_window(game.mlx, game.height, game.width, "So_long");
	check_img(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx, animation_loop, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
}
