/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:25:41 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:38:08 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks if the stack has duplicated value.
/// @param stack Pointer to the stack.
/// @return 1 if has duplicated value. 0 otherwise.
int	ft_check_duplicate(t_list **lst)
{
	t_list	*temp;
	t_list	*node;
	int		i;
	int		j;

	temp = (*lst);
	j = 0;
	while (temp)
	{
		node = (*lst);
		i = 0;
		while (i++ < j)
		{
			if (node->content == temp->content)
				return (1);
			node = node->next;
		}
		temp = temp->next;
		j++;
	}
	return (0);
}
