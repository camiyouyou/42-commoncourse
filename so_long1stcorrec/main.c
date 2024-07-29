/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:14:32 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 18:38:56 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(char **map, int start_row, int start_col)
{
	unsigned long	expected_length;
	unsigned long	j;
	int				i;

	i = start_row;
	j = start_col;
	expected_length = ft_strlen(map[start_row]);
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			j++;
		}
		if (j - start_col != expected_length)
			return (1);
		j = start_col;
		i++;
	}
	return (0);
}

int	get_cols(char **map)
{
	int	i;
	int	cols;
	int	current_cols;

	i = 0;
	cols = 0;
	while (map[i])
	{
		current_cols = ft_strlen(map[i]);
		if (current_cols > cols)
			cols = current_cols;
		i++;
	}
	return (i);
}

int	finish_check_walls(char **map, int i, int x, int y)
{
	while (i < x)
	{
		if (map [y - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map, int i, int j)
{
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = ft_strlen(map[0]);
	y = get_cols(map);
	while (i < x)
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (j < y)
	{
		if (map[j][0] != '1' || map[j][x - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	if (finish_check_walls(map, i, x, y))
		return (1);
	return (0);
}
