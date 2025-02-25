/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:54:54 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:36:08 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares the first `n` bytes of two memory blocks (`s1` and `s2`).
/// @param s1 Pointer to the first memory block.
/// @param s2 Pointer to the second memory block.
/// @param n Number of bytes to compare.
/// @return Returns an integer less than, equal to,
///		or greater than zero if the first `n` bytes of
/// 	`s1` are found, respectively,to be less than, to match,
///		or be greater than the first `n` bytes of `s2`.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
