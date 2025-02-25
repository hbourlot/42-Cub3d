/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:11:43 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:35:27 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies `n` bytes from memory area `src` to memory area `dest`.
/// @param dest Pointer to the destination memory area where content
///			is to be copied.
/// @param src Pointer to the source of data to be copied.
/// @param n Number of bytes to copy.
/// @return Pointer to `dest`.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
