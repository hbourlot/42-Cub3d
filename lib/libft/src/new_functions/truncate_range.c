/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:20:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/04 14:43:38 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Truncates a range of characters from a string.
/// Removes `n` characters starting from index `start` in the given string.
/// The string is modified in place, and the trailing part of the string
/// is shifted to fill the removed range. The string is properly
///	null-terminated.
/// @param src Pointer to the string to modify. The string must be
/// dynamically allocated or modifiable.
/// @param start The starting index from which characters will be removed.
/// Must be non-negative and within the length of the string.
/// @param bytes The number of characters to remove. Must be non-negative
///	and such that `start + n` does not exceed the length of the string.
/// @return 0 on success, -1 if the parameters are invalid or out of bounds.
int	truncate_range(char *src, int start, int bytes)
{
	int	length;
	int	i;
	int	pos;

	if (!src || start < 0 || bytes < 0)
		return (-1);
	length = ft_strlen(src);
	if (start >= length || (start + bytes) > length)
		return (-1);
	i = start;
	while ((i + bytes) < length)
	{
		src[i] = src[i + bytes];
		i++;
	}
	pos = length - bytes;
	while (pos - length)
	{
		src[pos] = '\0';
		pos++;
	}
	return (0);
}
