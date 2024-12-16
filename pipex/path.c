int path_finder(char **map)
{
    /*le principe de cette fonction est simple; une fois le */
}

char	*locate_path(char **split_path, char *cmd)
{
	int		i;
	int		flag_acss;
	char	*path;

	i = 0;
	while (split_path[i])
	{
		path = make_path(split_path[i], cmd);
		flag_acss = access(path, O_RDONLY);
		if (flag_acss == 0)
			return (path);
		else
		{
			free(path);
			i++;
		}
	}
	flag_acss = access(cmd, O_RDONLY);
	if (flag_acss == 0)
		return (cmd);
	return (NULL);
}