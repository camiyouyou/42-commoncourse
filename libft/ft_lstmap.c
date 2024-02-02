/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croussea <croussea@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:07:38 by croussea          #+#    #+#             */
/*   Updated: 2024/01/31 16:48:04 by croussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*tmp;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_elem = ft_lstnew(tmp);
		if (!new_elem)
		{
			del(tmp);
			while (new_list)
			{
				new_elem = new_list->next;
				del(new_list->content);
				free(new_list);
				new_list = new_elem;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
