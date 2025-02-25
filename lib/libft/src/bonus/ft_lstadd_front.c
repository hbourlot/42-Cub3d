/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:23:37 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:36:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds a new node to the beginning of a linked list.
/// @param lst A pointer to the pointer to the first node of the list.
/// @param new The new node to add to the front of the list.
void	ft_lst_add_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
