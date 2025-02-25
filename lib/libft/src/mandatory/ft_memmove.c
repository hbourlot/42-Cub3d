/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:48:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:35:20 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies `n` bytes from memory area `src` to memory area `dest`.
/// @param dest Pointer to the destination memory area where
///				content is to be copied.
/// @param src Pointer to the source of data to be copied.
/// @param n Number of bytes to copy.
/// @return Pointer to `dest`.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
