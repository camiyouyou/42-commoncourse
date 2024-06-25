/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:21:13 by croussea          #+#    #+#             */
/*   Updated: 2024/04/08 17:21:16 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*get_last_elem(t_list	*stash);
int		found_line(t_list *stash);
void	add_to_stash(char *buf, t_list **stash, int read_stuff);
char	*get_next_line(int fd);
void	read_and_stock(int fd, t_list **stash);
void	make_line(char **line, t_list *stash);
void	extract_line(t_list *stash, char **line);
void	free_stash(t_list *stash);
int		ft_strlen(char *s);
void	clean_stash(t_list **stash);

#endif
