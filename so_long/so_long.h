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

