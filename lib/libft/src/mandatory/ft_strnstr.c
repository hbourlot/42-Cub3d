/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:08:09 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/25 14:28:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of the null-terminated string 'little'
/// within the string 'big', where not more than 'len' characters are searched.
/// Characters that appear after a '\0' character are not searched.
/// @param big The string to search in.
/// @param little The substring to search for.
/// @param len The maximum number of characters to search within 'big'.
/// @return A pointer to the first occurrence of 'little' in 'big',
///	or NULL if 'little' is not found.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenth;
	char	*char_big;
	char	*char_little;

	char_little = (char *)little;
	char_big = (char *)big;
	i = 0;
	lenth = ft_strlen(little);
	if (lenth == 0)
		return ((char *)big);
	while (char_big && char_big[i] && i < len)
	{
		j = 0;
		while (char_big[i + j] == char_little[j] && i + j < len)
		{
			if (char_little[j + 1] == 0)
				return (char_big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
