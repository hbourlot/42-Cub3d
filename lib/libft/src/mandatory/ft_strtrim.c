/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:02:59 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/10 15:38:50 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/// @brief Checks if a character 'c' is present in the string 'set'.
/// @param c The character to search for.
/// @param set The string in which to search for the character.
/// @return 1 if 'c' is found in 'set', 0 otherwise.
static int	is_in(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/// @brief Allocates and returns a copy of 's1' with the leading and trailing
/// characters in 'set' removed.
/// @param s1 The string to trim.
/// @param set The set of characters to trim.
/// @return A newly allocated trimmed string, or NULL if allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	long long	start;
	long long	end;
	char		*temp;

	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	while (s1 && is_in(s1[start], set) == 1)
		start++;
	while (s1 && is_in(s1[end], set) == 1 && end != 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	temp = ft_substr(s1, start, end - start + 2);
	if (!temp)
		return (NULL);
	return (temp);
}
