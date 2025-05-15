/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_same_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:58:58 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/29 13:25:49 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks if all characters in the given string are the same
///          as the specified character.
/// @param src The string to be checked.
/// @param c The character to compare each character of the string against.
/// @return true if all characters in the string are the same as 'c',
///          false otherwise.
bool	all_same_char(const char *src, char c)
{
	size_t	i;

	i = 0;
	if (!src || *src == '\0')
		return (false);
	while (src[i])
	{
		if (src[i] != c)
			return (false);
		i++;
	}
	return (true);
}
