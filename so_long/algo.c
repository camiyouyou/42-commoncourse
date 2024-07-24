#include "so_long.h"

void	flood_fill(char **map, t_long *game, int x, int y)
{
      ft_printf("map flood\n");
	if (map[x][y] == '1')
		return;
	if (map[x][y] == 'K')
		return;
	if (map[x][y] == 'C')
	{
		game->count_c = game->count_c + 1;
		map[x][y] = 'K';
		flood_fill(map, game, x+1, y);
		flood_fill(map, game, x-1, y);
		flood_fill(map, game, x, y+1);
		flood_fill(map, game, x, y-1);
	}
	else
	{
		map[x][y] = 'K';
		flood_fill(map, game, x+1, y);
		flood_fill(map, game, x-1, y);
		flood_fill(map, game, x, y+1);
		flood_fill(map, game, x, y-1);
	}
	int i = 0;
	int j;
	while (map[i])
	{
	  j = 0;
	  while (map[i][j])
	  {
	    ft_printf("%s\n", map);
	    j++;
	  }
	  i++;
	}
}

int	main_algo(char **map, t_long *store)
{
	int	x;
	int	y;

	check_pos_p(map, store);
	check_pos_e(map, store);
	y = store->y;
	x = store->x;
	store->count_c = 0;
	flood_fill(map, store, x, y);
	x = 0;
	y = store->pos_e_y;
	x = store->pos_e_x;
	if (check_exit(map, store, x, y))
	{
		ft_printf("check exit good\n");
		return (0);
	}
	ft_printf("check exit failed\n");
	return (1);
}
