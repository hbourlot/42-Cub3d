/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:28:29 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/19 13:54:25 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Returns the value at a specified index in the list.
/// @param lst Pointer to the stack.
/// @param idx Index of the desired element.
/// @return The value at the specified index,
///	or 0 if the index is out of bounds.
int	stack_value(t_list **node, int idx)
{
	t_list	*temp;

	temp = (*node);
	while (idx >= 0 && idx--)
	{
		if (temp->next == NULL)
			return (*(int *)temp->content);
		temp = temp->next;
	}
	return (*(int *)temp->content);
}
