#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include "minilibx-linux/mlx.h"

typedef struct game
{
	char	**map;
	int	p;
	int	e;
	int	c;
	int	count_c;
	int	x;
	int	y;
	int	coord_y;
	int	coord_x;
	int	moves;
	int	total_c;
	void	*mlx;
	void	*window;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
}	t_game

// ajouter get_next_line, split, join, strlen, strdup;
//

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
