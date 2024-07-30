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

void	suite_moov_n(t_game *g, int n)
{
	g->moves = g->moves + 1;
	ft_put_action(g->moves);
	if (g->map[g->pos_y][g->pos_x] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_e,
			g->pos_x * 100, g->pos_y * 100);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			g->pos_x * 100, g->pos_y * 100);
	}
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, n * 100, g->pos_y * 100);
	g->pos_x = n;
}

void	suite_moov_p(t_game *g, int p)
{
	g->moves = g->moves + 1;
	ft_put_action(g->moves);
	if (g->map[g->pos_y][g->pos_x] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_e,
			g->pos_x * 100, g->pos_y * 100);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			g->pos_x * 100, g->pos_y * 100);
	}
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, g->pos_x * 100, p * 100);
	g->pos_y = p;
}

void	draw_exit(t_game *g, int x, int y)
{
	g->moves = g->moves + 1;
	ft_put_action(g->moves);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
		g->pos_x * 100, g->pos_y * 100);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_e, x * 100, y * 100);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_chat, x * 100, y * 100);
}
