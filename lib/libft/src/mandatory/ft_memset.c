/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:55:45 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:35:13 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Sets `n` bytes of memory starting from `s` to the value `c`.
/// @param s Pointer to the memory area where bytes are to be set.
/// @param c Value to be set. This is treated as an unsigned char
///			and is converted to `unsigned char` before being written.
/// @param n Number of bytes to be set to the value `c`.
/// @return Pointer to the memory area `s`.
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (const char)c;
		i++;
	}
	return ((void *)s);
}
