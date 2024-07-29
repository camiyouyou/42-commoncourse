/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:34:38 by croussea          #+#    #+#             */
/*   Updated: 2024/07/28 20:34:41 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int j, int i, char *str)
{
	mlx_put_image_to_window(game->mlx, game->wdw, str,
		j * 100, i * 100);
}

void	put_texture(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0,
					j * 100, i * 100);
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_1,
					j * 100, i * 100);
			if (map[i][j] == 'C')
				put_image(game, j, i, game->img_c);
			if (map[i][j] == 'E')
				put_image(game, j, i, game->img_e);
			if (map[i][j] == 'P')
				put_image(game, j, i, game->img_p);
			j++;
		}
		i++;
	}
}

char	**save_map(char **map, int fd)
{
	char	*line;
	char	*full_line;

	full_line = NULL;
	line = malloc(sizeof(char));
	full_line = malloc(sizeof(char));
	if (!line || !full_line)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		full_line = ft_strjoin(full_line, line);
	}
	map = ft_split(full_line, '\n');
	free(full_line);
	return (map);
}

int	map_mng(int fd)
{
	char	**map;
	char	**map_copy;
	t_long	*store;

	map = NULL;
	map_copy = NULL;
	store = malloc(sizeof(t_long));
	if (!store)
		return (1);
	map = save_map(map, fd);
	if ((check_map_main(map, store)) != 0)
	{
		free_map(map);
		return (1);
	}
	map_copy = copy_map(map);
	if (!main_algo(map_copy, store))
	{
		free_map(map);
		free_map(map_copy);
	}
	free_map(map_copy);
	show_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*file_name;

	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return (ft_printf("Error\nBad file name.\n"));
	if (argc != 2)
		return (ft_printf("Error\nNumber of argument(s) invalid.\n"));
	if (check_extension(file_name, 0) == 0)
		return (ft_printf("Error\nBad extension.\n"));
	map_mng(fd);
}
