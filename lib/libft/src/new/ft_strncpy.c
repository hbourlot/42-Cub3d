/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:37:37 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/10 00:18:02 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies up to `n` characters from the string `src`
///			to the buffer `dest`,
///			padding with `\0` if `src` is shorter than `n`.
/// @param dest The destination buffer where the string is copied.
/// @param src The source string to be copied.
/// @param n The maximum number of characters to copy from `src`.
/// @return A pointer to the destination buffer `dest`.
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
