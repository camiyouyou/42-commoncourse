#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	texture_init(t_game *game)
{
	game->path_0 = "xpm/grass.xpm";
	game->path_1 = "xpm/arbre1.xpm";
	game->path_c = "xpm/fraise1.xpm";
	game->path_e = "xpm/tapis1.xpm";
	game->path_p = "xpm/chat1.xpm";
	ft_printf("texture set succesfully\n");
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
	ft_printf("map saved to structure\n");
}

int	mng_input(int key, t_game *game)
{
ft_printf("managing input\n");
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = game->pos_x - 1;
	y1 = game->pos_y - 1;
	x2 = game->pos_x + 1;
	y2 = game->pos_y + 1;
	if (key == XK_Left || key == XK_A)
		key_horiz(game, x1);
	if (key == XK_Right || key == XK_D)
		key_horiz(game, x2);
	if (key == XK_Up || key == XK_S)
		key_vert(game, y1);
	if (key == XK_Down || key == XK_W)
		key_vert(game, y2);
	if (key == XK_Escape)
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
	ft_printf("info checked succesfully\n");
}

void	show_map(char **map)
{
	t_game game;
	int	width;
	int	height;

	texture_init(&game);
	info_map(map, &game);
	map_to_struct(map, &game, 0, 0);
	game.mlx = mlx_init();
	game.wdw = mlx_new_window(game.mlx, game.len_x * 100, game.len_y * 100, "so_long");
	game.img_0 = mlx_xpm_file_to_image(game.mlx, game.path_0, &width, &height);
	check_img(game.img_0);
	game.img_1 = mlx_xpm_file_to_image(game.mlx, game.path_1, &width, &height);
	check_img(game.img_1);
	game.img_c = mlx_xpm_file_to_image(game.mlx, game.path_c, &width, &height);
	check_img(game.img_c);
	game.img_e = mlx_xpm_file_to_image(game.mlx, game.path_e, &width, &height);
	check_img(game.img_e);
	game.img_p = mlx_xpm_file_to_image(game.mlx, game.path_p, &width, &height);
	check_img(game.img_p);
	put_texture(&game, map);
	mlx_key_hook(game.wdw, mng_input, &game);
	ft_printf("key should be handled\n");
	mlx_hook(game.wdw, 17, 0, exit_game, &game);
	ft_printf("exit through escape should be handled\n");
	mlx_loop(game.mlx);
	ft_printf("window should be open\n");
}

void  key_vert(t_game *g, int p)
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
        exit(1);
    }
    else
        return ;
  }
  g->moves = g->moves + 1;
  ft_put_action(g->moves);
  mlx_put_image_to_window(g->mlx, g->wdw, g->img_0, g->pos_x *100, g->pos_y *100);
  mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, g->pos_x *100, p *100);
  g->pos_y = p;
}

void ft_put_action(int nb)
{
  ft_printf("Number of moves: %d\n", nb);
}

void  key_horiz(t_game *g, int n)
{
  if (g->map[g->pos_y][n] == '1')
    return ;
  if (g->map[g->pos_y][n] == 'C')
  {
    g->map[g->pos_y][n] = '0';
    g->count_c = g->count_c + 1;
    mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
          g->pos_y * 100, n * 100);
  }
  if (g->map[g->pos_y][n] == 'E')
  {
    if (g->count_c == g->c_pos)
    {
        mlx_destroy_window(g->mlx, g->wdw);
        exit_game(g);
    }
    else
        return ;
  }
  g->moves = g->moves + 1;
  ft_put_action(g->moves);
  mlx_put_image_to_window(g->mlx, g->wdw, g->img_0, g->pos_x *100, g->pos_y *100);
  mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, n *100, g->pos_y *100);
  g->pos_x = n;
}
