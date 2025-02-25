/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstidx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:30:01 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:51:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Returns the index of the given value in the list, or
///			-1 if not found.
/// @param node A pointer to the pointer to the head of the
///			list (linked list).
/// @param value The value to find in the list.
/// @return The index of the value in the list, or
///			-1 if the value is not found.
int	stack_idx(t_list **node, int value)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = (*node);
	if (*node)
	{
		while (temp)
		{
			if (*(int *)temp->content == value)
				return (i);
			i++;
			temp = temp->next;
		}
	}
	return (-1);
}
