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

int	mem_ligne(char **map, int mem, int mem_word)
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

	mem =
	mem_ligne =
	copy = 
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
