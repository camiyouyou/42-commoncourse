/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:21:02 by croussea          #+#    #+#             */
/*   Updated: 2024/04/08 17:21:04 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_stock(int fd, t_list **stash)
{
	char	*buf;
	int		read_stuff;

	read_stuff = 1;
	while (!stash || (!found_line(*stash) && read_stuff != 0))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		read_stuff = read(fd, buf, BUFFER_SIZE);
		if (read_stuff == -1)
		{
			free_stash(*stash);
			free(buf);
			return ;
		}
		buf[read_stuff] = '\0';
		add_to_stash(buf, stash, read_stuff);
		free(buf);
	}
}

// generate a new line / get line
void	make_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	(*line)[len] = '\0';
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	make_line(line, stash);
	if (*line == NULL || stash == NULL)
		return ;
	j = 0;
	while (stash && stash->content)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i++];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

//free stash
void	free_stash(t_list *stash)
{
	t_list	*tmp;

	if (NULL == stash)
		return ;
	while (stash)
	{
		tmp = stash->next;
		free(stash->content);
		free(stash);
		stash = tmp;
	}
	stash = NULL;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
