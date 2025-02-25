/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:36:38 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:36:00 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds a new node to the end of a linked list.
/// @param lst A pointer to the pointer to the first node of the list.
/// @param new The new node to add to the end of the list.
void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		current = NULL;
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
