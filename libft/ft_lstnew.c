/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:05:11 by croussea          #+#    #+#             */
/*   Updated: 2024/01/31 12:25:40 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*entry;

	entry = (t_list *)malloc(sizeof(*entry));
	if (entry == NULL)
		return (NULL);
	entry->content = content;
	entry->next = NULL;
	return (entry);
}
