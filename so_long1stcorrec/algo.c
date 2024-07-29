/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:22 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 17:34:27 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_long *game, int x, int y)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'K')
		return ;
	if (map[x][y] == 'C')
	{
		game->count_c = game->count_c + 1;
		map[x][y] = 'K';
		flood_fill(map, game, x +1, y);
		flood_fill(map, game, x -1, y);
		flood_fill(map, game, x, y +1);
		flood_fill(map, game, x, y -1);
	}
	else
	{
		map[x][y] = 'K';
		flood_fill(map, game, x +1, y);
		flood_fill(map, game, x -1, y);
		flood_fill(map, game, x, y +1);
		flood_fill(map, game, x, y -1);
	}
}

int	main_algo(char **map, t_long *store)
{
	int	x;
	int	y;

	check_pos_p(map, store);
	check_pos_e(map, store);
	x = store->y;
	y = store->x;
	flood_fill(map, store, x, y);
	x = 0;
	y = store->pos_e_y;
	x = store->pos_e_x;
	if (check_exit(map, store, x, y))
	{
		return (0);
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
