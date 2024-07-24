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
{
	char	**map;
	int	moves;
	int	count_c;
	int	c_pos;
	int     len_x;
	int     len_y;
	int	pos_x;
	int	pos_y;
	void	*mlx;
	void	*wdw;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	void    *path_0;
	void    *path_1;
	void    *path_c;
	void    *path_e;
	void    *path_p;
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
unsigned long ft_strlen(char *s);
size_t	ft_strlcpy(char *restrict dst, char *restrict src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
void    key_horiz(t_game *g, int n);
void    ft_put_action(int nb);
void    key_vert(t_game *g, int p);
int    ft_putnbr_ap(int n, int base);
int    ft_putstr_ap(char *s);
int    ft_putchar_ap(int c);
int    ft_hexa(unsigned long n, char format);
int	ft_putunsigned(unsigned int n);
int ft_print_ptr(size_t nbr);
int ft_ptr(size_t num);
int print_format(char s, va_list ap);
int ft_printf(const char *s, ...);
void	flood_fill(char **map, t_long *game, int x, int y);
int	main_algo(char **map, t_long *store);
int	mem_colonne(char **map, int mem, int mem_ligne);
int	mem_ligne(char **map, int mem, int mem_word);
char	**copy_map(char **map, int mem, int mem_ligne);

#endif


