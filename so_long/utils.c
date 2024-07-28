#include "so_long.h"

void	free_map(char **map)
{
	int	i;
	
	i = 0;
	ft_printf("freeing map\n");
	while (map[i])
        {
		  free(map[i]);
		  i++;
	}
	free(map);

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
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_c,
					j * 100, i * 100);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_e,
					j * 100, i * 100);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_p,
					j * 100, i * 100);
			j++;
		}
		i++;
	}
	ft_printf("texture set succesfully\n");
}

char **save_map(char **map, int fd)
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
		//remove after debug
		ft_printf("%s\n", full_line);
	}
	map = ft_split(full_line, '\n');
	free(full_line);
	ft_printf("map saved succesfully\n");
	return (map);
}

int map_mng(int fd)
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
	  ft_printf("freed map\n");
	  free_map(map_copy);
	  ft_printf("freed map copy\n");
	  return(ft_printf("Error\nMap cannot be played\n"));
	}
	free_map(map_copy);
	ft_printf("map copy freed succesfully\n");
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
