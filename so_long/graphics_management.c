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

void	info_map(char **map, t_game *game)
{
	int	y;
	int	x;

	game->nb_action = 0;
	game->c_p = 0;
	game->c_tot = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->c_tot = game->c_tot + 1;
			if (map[y][x] == 'P')
			{
				game->ply_x = x;
				game->ply_y = y;
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
	t_game game;
	int	width;
	int	length;

	texture_init(&game);
	info_map(map, &game);
	map_to_struct(map, &game, 0, 0);
	game.mlx = mlx_init();
	game.wdw = mlx_new_window(game.mlx, game.len_x * 100, game len_y * 100, "so_long");
	game.img_0 = mlx_xpm_file_to_image(game.mlx, game.path_0, &img_w, &img_h);
	check_img(game.img_0);
	game.img_1 = mlx_xpm_file_to_image(game.mlx, game.path_1, &img_w, &img_h);
	check_img(game.img_1);
	game.img_c = mlx_xpm_file_to_image(game.mlx, game.path_c, &img_w, &img_h);
	check_img(game.img_c);
	game.img_e = mlx_xpm_file_to_image(game.mlx, game.path_e, &img_w, &img_h);
	check_img(game.img_e);
	game.img_p = mlx_xpm_file_to_image(game.mlx, game.path_p, &img_w, &img_h);
	check_img(game.img_p);
	put_texture(&game, map);
	mlx_key_hook(game.wdw, mng_input, &game);
	mlx_hook(game.wdw, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}
