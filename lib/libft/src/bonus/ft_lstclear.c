/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:01:35 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:36:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Deletes an entire linked list.
/// @param lst A pointer to the pointer to the first node of the list.
/// @param del The function used to delete the content of each node.
void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = temp;
	}
	lst = NULL;
}
