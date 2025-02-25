/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:24:41 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/20 14:44:32 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Initializes the `prev` pointers of a doubly linked list.
///			This function traverses a singly linked list
///			(using the `next` pointer) and sets up the `prev`
///			pointers to correctly link nodes in both directions.
/// @param node Pointer to the first node in the list.
/// @param prev_offset Byte offset of the `prev` pointer in the struct.
/// @param next_offset Byte offset of the `next` pointer in the struct.
void	init_prev(void *node, size_t prev_offset, size_t next_offset)
{
	char	*next;
	char	*tmp;

	tmp = (char *)node;
	if (!tmp)
		return ;
	*(void **)(tmp + prev_offset) = NULL;
	while (*(void **)(tmp + next_offset))
	{
		next = *(void **)(tmp + next_offset);
		*(void **)(next + prev_offset) = tmp;
		tmp = next;
	}
}
