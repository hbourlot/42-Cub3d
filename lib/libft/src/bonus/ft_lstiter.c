/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:01:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:46:57 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates through a linked list and applies a 
///			function to each element.
/// @param lst The beginning of the linked list.
/// @param f The function to apply to each element's content.
void	ft_lst_iter(t_list *lst, void (*f)(void *))
{
	t_list	*list;

	if (!lst || !f)
		return ;
	list = lst;
	f(list->content);
	list = list->next;
	if (list)
		ft_lst_iter(list, f);
}
