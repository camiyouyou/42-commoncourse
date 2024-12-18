/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:22:55 by croussea          #+#    #+#             */
/*   Updated: 2024/01/19 11:49:37 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	count_lines(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
		{
			i++;
		}
	}
	return (count);
}

size_t	get_line_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char	**split(char const *s, char c, char **array, size_t line_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < line_count)
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, get_line_len(&s[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**new;

	if (!s)
		return (NULL);
	len = count_lines(s, c);
	new = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);
	new = split(s, c, new, len);
	return (new);
}
