/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:11:00 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:44:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of byte `c` in the memory
///				block pointed to by `s`.
/// @param s Pointer to the memory block to be searched.
/// @param c Value to be located. The value is interpreted
///				as an unsigned char.
/// @param n Number of bytes to be searched.
/// @return Pointer to the first occurrence of `c` within the
///			first `n` bytes of `s`, or NULL if `c` is not found.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}
