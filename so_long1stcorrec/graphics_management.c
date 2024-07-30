/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:46:26 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 18:12:37 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	texture_init(t_game *game)
{
	game->path_0 = "xpm/grass.xpm";
	game->path_1 = "xpm/arbre1.xpm";
	game->path_c = "xpm/fraise1.xpm";
	game->path_e = "xpm/tapis1.xpm";
	game->path_p = "xpm/chat1.xpm";
	game->path_chat = "xpm/overlay.xpm";
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wdw);
	free(game->mlx);
	exit(1);
}

void	key_vert(t_game *g, int p)
{
	if (g->map[p][g->pos_x] == '1')
		return ;
	if (g->map[p][g->pos_x] == 'C')
	{
		g->map[p][g->pos_x] = '0';
		g->count_c = g->count_c + 1;
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			g->pos_x * 100, p * 100);
	}
	if (g->map[p][g->pos_x] == 'E')
	{
		if (g->count_c == g->c_pos)
		{
			mlx_destroy_window(g->mlx, g->wdw);
			exit (1);
		}
		else
		{
			draw_exit(g, g->pos_x, p);
			g->pos_y = p;
		}
	}
	else
		suite_moov_p(g, p);
}

void	ft_put_action(int nb)
{
	ft_printf("Number of moves: %d\n", nb);
}

void	key_horiz(t_game *g, int n)
{
	if (g->map[g->pos_y][n] == '1')
		return ;
	if (g->map[g->pos_y][n] == 'C')
	{
		g->map[g->pos_y][n] = '0';
		g->count_c = g->count_c + 1;
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			n * 100, g->pos_y * 100);
	}
	if (g->map[g->pos_y][n] == 'E')
	{
		if (g->count_c == g->c_pos)
		{
			mlx_destroy_window(g->mlx, g->wdw);
			exit(1);
		}
		else
		{
			draw_exit(g, n, g->pos_y);
			g->pos_x = n;
		}
	}
	else
		suite_moov_n(g, n);
}
