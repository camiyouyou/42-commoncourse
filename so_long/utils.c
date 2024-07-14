void	free_map(char **map)
{
	int	i;
  int j;

	i = 0;
	while (map[i][j])
  {
    j = 0;
    while (map[i])
	  {
		  free(map[i][j]);
		  i++;
	  }
    j++;
  }
	  free(map);
}
