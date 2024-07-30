/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:31:06 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 20:31:09 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_struct(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' ||
			map[i][j] == 'E' || map[i][j] == 'P' ||
			map[i][j] == 'C')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_exit(char **map, t_long *game, int x, int y)
{
	ft_printf("%c\n", map[y][x]);
	if (game->c == game->count_c)
	{
		if (map[y][x] == 'K')
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	else
		return (1);
}

int	check_extension(char *name, int i)
{
	i = 0;
	while (name[i])
	{
		if (name[i] == '.')
		{
			if (name[++i] == 'b')
			{
				if (name[++i] == 'e')
				{
					if (name[++i] == 'r')
						return (0);
					return (1);
				}
				return (1);
			}
			return (1);
		}
		i++;
	}
	return (1);
}

void	check_pos_e(char **map, t_long *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				game->pos_e_y = y;
				game->pos_e_x = x;
			}
			x++;
		}
		y++;
	}
}

void	check_pos_p(char **map, t_long *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
			}
			x++;
		}
		y++;
	}
}
