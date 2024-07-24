#include "so_long.h"

int	mem_colonne(char **map, int mem, int mem_ligne)
{
	while (map[mem])
	{
		mem_ligne = 0;
		while (map[mem][mem_ligne])
			mem_ligne++;
		mem++;
	}
	return (mem);
}

int	mem_line(char **map, int mem, int mem_ligne)
{
	while (map[mem])
	{
		mem_ligne = 0;
		while(map[mem][mem_ligne])
			mem_ligne++;
		mem++;
	}
	return (mem_ligne);
}

char	**copy_map(char **map, int mem, int mem_ligne)
{
	char	**copy;
	int	i;
	int	j;

	mem = mem_colonne(map, mem, mem_ligne);
	mem_ligne = mem_line(map, mem, mem_ligne);
	copy = malloc((mem + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	copy[i][j] = '\0';
	return (copy);
}
