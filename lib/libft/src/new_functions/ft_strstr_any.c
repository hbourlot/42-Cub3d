/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_any.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:35:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/29 13:29:05 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the first occurrence of any substring
///			 from the `needles` array in the string `haystack`.
/// @param haystack The main string to be searched.
/// @param needles An array of substrings to search for in `haystack`.
/// @return A pointer to the first occurrence of any substring from
///		 `needles` in `haystack`, or NULL if no match is found.
char	*ft_strstr_any(const char *haystack, const char **needles)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!haystack || !*haystack)
		return (NULL);
	if (!*needles)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = -1;
		while (needles[++j])
		{
			k = 0;
			while (haystack[i + k] && haystack[i + k] == needles[j][k])
			{
				k++;
				if (!needles[j][k])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
