/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:52:06 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/04 15:35:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Function to get the last node of a linked list dynamically
/// @param node Pointer to the first node of the list
/// @param next_offset Offset of the `next` pointer within the struct
/// @return Pointer to the last node in the list
void	*get_last_node(void *node, size_t next_offset)
{
	char	*tmp;

	tmp = (char *)node;
	if (!tmp)
		return (NULL);
	while (*(void **)(tmp + next_offset))
		tmp = *(char **)(tmp + next_offset);
	return ((void *)tmp);
}
