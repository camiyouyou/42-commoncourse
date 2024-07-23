#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include "minilibx-linux/mlx.h"

typedef struct so_long
{
	char	**map;
	int	p;
	int	e;
	int	c;
	int	count_c;
	int	x;
	int	y;
	int	pos_e_y;
	int	pos_e_x;
	int	pos_p_y;
	int	pos_p_x;	
}	t_long;

typedef struct game
	char	**map;
	int	moves;
	int	count_c;
	int	c_pos;
	int	pos_x;
	int	pos_y;
	void	*mlx;
	void	*window;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
}	t_game;

// ajouter get_next_line, split, join, strlen, strdup;
//

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int	check_components(char **map, int i, int j, t_long *check);
int	check_duplicate(int i);
void	texture_init(t_game *game);
void	check_img(void *img);
void	map_to_struct(char **map, t_game *map_struct, int x, int y);
int	mng_input(int key, t_game *game);
int	exit_game(t_game *game);
void	info_map(char **map, t_game *game);
void	show_map(char **map);
int	check_rectangle(char **map, int i, int j, int x);
int	get_cols(char **map);
int	check_walls(char **map, int i, int j);
int	check_struct(char **map, int i, int j);
int	check_exit(char **map, t_long *game, int x, int y);
int	check_extension(char *name, int i);
void	check_pos_e(char **map, t_long *game);
void	check_pos_p(char **map, t_long *game);
int	check_map_main(char **map, t_long *check);
void	free_map(char **map);
void	put_texture(t_game *game, char **map);
char	**save_map(char **map, int fd);
int	map_mng(int fd);


