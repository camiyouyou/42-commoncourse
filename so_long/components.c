int	check_components(char **map, int i, int j, t_long *check)
{
	int	c;

	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				store->c = c++;
			if (map[i][j] == 'E')
				check->e = check_duplicate(check->e);
			if (map[count][count_2] == 'P')
				check->p = check_duplicate(check->p);
			j++;
		}
		i++;
	}
	if (check->c > 0 && check->e == 1 && check->p == 1)
		return (0);
	else
		return (1);
}

int	check_duplicate(int i)
{
	if (i)
		return (2);
	else if (i == 0)
		return (1);
	return (2);
}
