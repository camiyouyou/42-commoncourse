/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:36:42 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 17:54:34 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_main(char **map, t_long *check)
{
	check->c = 0;
	check->p = 0;
	check->e = 0;
	if (check_struct(map, 0, 0))
		return (ft_printf("Error\n probleme de structure\n"));
	if (check_rectangle(map, 0, 0))
		return (ft_printf("Error\n map is not rectangle\n"));
	if (check_walls(map, 0, 0))
		return (ft_printf("Error\n map is not surrounded by walls\n"));
	if (check_components(map, 0, 0, check))
		return (ft_printf("Error\n number of component error\n"));
	return (0);
}

void	map_to_struct(char **map, t_game *map_struct, int x, int y)
{
	int	i;
	int	j;

	y = get_cols(map);
	x = ft_strlen(map[0]);
	map_struct->map = malloc((y + 1) * sizeof(char *));
	if (!map_struct->map)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		map_struct->map[i] = malloc((x) * sizeof(char *));
		if (!map_struct->map[i])
			return ;
		while (map[i][j])
		{
			map_struct->map[i][j] = map[i][j];
			j++;
		}
		map_struct->map[i][j] = '\0';
		i++;
	}
	map_struct->map[i] = NULL;
}

int	mng_input(int key, t_game *game)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = game->pos_x - 1;
	y1 = game->pos_y - 1;
	x2 = game->pos_x + 1;
	y2 = game->pos_y + 1;
	if (key == XK_Left || key == XK_a)
		key_horiz(game, x1);
	if (key == XK_Right || key == XK_d)
		key_horiz(game, x2);
	if (key == XK_Up || key == XK_w)
		key_vert(game, y1);
	if (key == XK_Down || key == XK_s)
		key_vert(game, y2);
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->wdw);
		free_map(game->map);
		free(game->mlx);
		exit(1);
	}
	return (0);
}

void	check_img(void *img)
{
	if (img == NULL)
		exit(2);
}

int	check_access(t_long *store)
{
	int	total;
	total = store->n0 + store->count_c;

	if (total == store->k)
		return (1)
	return (0);
}
