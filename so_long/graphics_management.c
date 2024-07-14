#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void	texture_init(t_game *game)
{
	game->path_0 = "xpm/arbre1.xpm";
	game->path_1 = "xpm/grass.xpm";
	game->path_c = "xpm/fraise1.xpm";
	game->path_e = "xpm/tapis1.xpm";
	game->path_p = "xpm/chat1.xpm";
}

void check_img(void *img)
{
	if(img == NULL)
		exit(2);
}

void	map_to_struct(char **map, t_game *map_struct, int x, int y)
{
	int	i;
	int	j;

	y = get_cols(map);
	x = ft_strlen(map[0]);
	map_struct->map = malloc((x + 1) * sizeof(char *));
	if (!map_struct->map)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		map_struct->map[i] = malloc((y) * sizeof(char *));
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
	if (key == 0 || key == 123)
		key_horiz(game, x1);
	if (key == 2 || key == 124)
		key_horiz(game, x2);
	if (key == 13 || key == 126)
		key_vert(game, y1);
	if (key == 1 || key == 125)
		key_vert(game, y2);
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->wdw);
		free_map(game->map);
		free(game->mlx);
		exit(1);
	}
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wdw);
	free(game->mlx);
	exit(1);
}
