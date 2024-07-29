/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:59:16 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 19:08:20 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mem_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	mem_colonne(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{
		j++;
	}
	return (j);
}

int	copy_map2(char **map, int i, int j, char **copy)
{
	int	len;

	len = 0;
	while (map[i][len] && map[i][len] != '\n')
		len++;
	copy[i] = (char *)malloc((len + 1) * sizeof(char));
	if (!copy[i])
	{
		while (i-- > 0)
			free(copy[i]);
		free(copy);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		copy[i][j] = map[i][j];
		j++;
	}
	copy[i][j] = '\0';
	i++;
	return (i);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
	int		mem;

	i = 0;
	j = 0;
	mem = mem_line(map);
	copy = (char **)malloc((mem + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < mem)
	{
		i = copy_map2(map, i, j, copy);
	}
	copy[i] = NULL;
	return (copy);
}

void	put_both(t_game *game, int j, int i, char *str)
{
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_e,
		j * 100, i * 100);
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_chat,
		j * 100, i * 100);
}
