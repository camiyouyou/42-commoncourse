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

char	**copy_map(char **map, int mem, int mem_word)
{
  ft_printf("copying map");
	char	**copy;
	int	i;
	int	j;

	mem = mem_line(map, mem, mem_word);
	mem_word = mem_colonne(map, mem, mem_word);
	copy = malloc((mem + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		copy[i] = malloc((mem_word) * sizeof(char *));
		if (!copy[i])
		  return (NULL);
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	copy[i] = '\0';
	ft_printf("copied map");
	return (copy);
}
