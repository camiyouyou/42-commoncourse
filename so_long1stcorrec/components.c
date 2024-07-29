/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:44:43 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 17:59:41 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_components(char **map, int i, int j, t_long *check)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				check->c = check->c + 1;
				// ajouter fonction check alrededores
			if (map[i][j] == 'E')
			{
				// ajouter fonction check alrededores
				check->e = check_duplicate(check->e);
			}
			if (map[i][j] == 'P')
			{
				check->p = check_duplicate(check->p);
			}
			j++;
		}
		i++;
	}
	if (check->c > 0 && check->e == 1 && check->p == 1)
		return (0);
	else
		return (1);
}

int	check_duplicate(int X)
{
	if (X == 0)
		return (1);
	else
	{
		return (2);
	}
}

void	info_map(char **map, t_game *game)
{
	int	y;
	int	x;

	game->moves = 0;
	game->c_pos = 0;
	game->count_c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->c_pos = game->c_pos + 1;
			if (map[y][x] == 'P')
			{
				game->pos_x = x;
				game->pos_y = y;
			}
			x++;
		}
		y++;
	}
	game->len_y = y;
	game->len_x = x;
}

void	show_map(char **map)
{
	int		width;
	int		height;
	t_game	g;

	texture_init(&g);
	info_map(map, &g);
	map_to_struct(map, &g, 0, 0);
	g.mlx = mlx_init();
	g.wdw = mlx_new_window(g.mlx, g.len_x * 100, g.len_y * 100, "so_long");
	g.img_0 = mlx_xpm_file_to_image(g.mlx, g.path_0, &width, &height);
	check_img(g.img_0);
	g.img_1 = mlx_xpm_file_to_image(g.mlx, g.path_1, &width, &height);
	check_img(g.img_1);
	g.img_c = mlx_xpm_file_to_image(g.mlx, g.path_c, &width, &height);
	check_img(g.img_c);
	g.img_e = mlx_xpm_file_to_image(g.mlx, g.path_e, &width, &height);
	check_img(g.img_e);
	g.img_p = mlx_xpm_file_to_image(g.mlx, g.path_p, &width, &height);
	check_img(g.img_p);
	put_texture(&g, map);
	mlx_key_hook(g.wdw, mng_input, &g);
	mlx_hook(g.wdw, 17, 0, exit_game, &g);
	mlx_loop(g.mlx);
}
