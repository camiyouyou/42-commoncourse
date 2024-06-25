/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:20:49 by croussea          #+#    #+#             */
/*   Updated: 2024/04/08 17:20:52 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_last_elem(t_list *stash)
{
	t_list	*node;

	node = stash;
	while (node && node->next)
		node = node->next;
	return (node);
}

int	found_line(t_list *stash)
{
	int		i;
	t_list	*node;

	if (stash == NULL)
		return (0);
	node = get_last_elem(stash);
	i = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	add_to_stash(char *buf, t_list **stash, int read_stuff)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL || stash == NULL)
		return ;
	new->next = NULL;
	new->content = malloc (sizeof(char) * (read_stuff + 1));
	if (new->content == NULL)
		return ;
	i = 0;
	while (buf[i] != '\0' && i < read_stuff)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last = get_last_elem(*stash);
	last->next = new;
}

//clean stash after reading line so as to pass to next line. 
// only cleans relevant characters

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (stash == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = get_last_elem(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1);
	if (clean->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0 || fd < 0)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	read_and_stock(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* int	main()
{
	
	int	fd;
	char *line;

	fd = open("read_error.txt" , O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/
