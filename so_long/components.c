#include "so_long.h"

int	check_components(char **map, int i, int j, t_long *check)
{
        int c;
        int e;
        int p;
        
        check->c = 0;
        c = 0;
        p = 0;
        e = 0;
	i = 0;
	ft_printf("checking components\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				check->c = c++;
			if (map[i][j] == 'E')
				check->e = e++;
			if (map[i][j] == 'P')
				check->p = p++;
			j++;
		}
		i++;
	}
	ft_printf("collectible : %d", check->c);
	ft_printf("exit : %d", check->e);
	ft_printf("perso : %d", check->p);
	if (check->c > 0 && check->e == 1 && check->p == 1)
		return (0);
	else
		return (1);
}

int	check_duplicate(int X)
{
	ft_printf("checking duplicates\n");
	if (X == 0)
		return (1);
	else
		return (2);
}
