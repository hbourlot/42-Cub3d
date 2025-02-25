/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:24:27 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:45:55 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates the linked list 'lst' and applies the function 
///			'f' to each element. Uses function 'del' to delete the
///			 element if the memory allocation fails.
/// @param list The beginning of the linked list.
/// @param f The function to apply to each element.
/// @param del The function to delete the element.
/// @return A new linked list resulting from the successive applications of 'f'.
t_list	*ft_lst_map(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*item;

	head = NULL;
	if (!list || !f || !del)
		return (NULL);
	while (list)
	{
		item = f(list->content);
		node = ft_lst_new(item);
		if (!node)
		{
			del(item);
			ft_lst_clear(&head, (*del));
			return (head);
		}
		ft_lst_add_back(&head, node);
		list = list->next;
	}
	return (head);
}
