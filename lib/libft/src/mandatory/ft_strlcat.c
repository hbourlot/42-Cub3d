/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:50:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:34:00 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Concatenates strings while ensuring no buffer overflow.
/// @param dst The destination buffer to which `src` will be appended.
/// @param src The source string to append to `dst`.
/// @param size The size of the destination buffer `dst`.
/// @return The total length of the concatenated string (initial length of dst
///	+ length of src).
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	len_dst;

	len_dst = 0;
	i = 0;
	l = 0;
	while (dst[l] && l < size)
	{
		l++;
		len_dst++;
	}
	if (size <= l)
		return (l + ft_strlen(src));
	while (src[i] && l < size - 1)
	{
		dst[l] = src[i];
		i++;
		l++;
	}
	dst[l] = '\0';
	return (ft_strlen(src) + len_dst);
}
