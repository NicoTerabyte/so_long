/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:09:07 by lnicoter          #+#    #+#             */
/*   Updated: 2023/03/15 18:26:26 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	argv_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		return (1);
	return (0);
}

char	**read_map(char *file, t_game *game)
{
	char		*stringona;
	int			fd;

	if (argv_check(file) != 1)
	{
		ft_printf("Error\nthe map is not a .ber\n");
		exit(1);
	}
	stringona = malloc(sizeof(char) * 10000000);
	fd = open(file, O_RDONLY);
	read(fd, stringona, 10000000);
	game->map = ft_split(stringona, '\n');
	close(fd);
	free(stringona);
	return (game->map);
}
