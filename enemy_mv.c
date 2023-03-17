/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:20 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 17:59:24 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontal(t_game *game)
{
	static int	time;

	if (time == 25)
	{
		check_movement_enemyh_plus(game);
		check_movement_enemyh_minus(game);
		time = 0;
	}
	time++;
	draw_map(game);
	return (0);
}
