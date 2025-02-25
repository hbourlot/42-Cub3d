/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:04:42 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/28 16:47:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of character
///			c in string s.
/// @param s The string to be searched.
/// @param c The character to search for.
/// @return Returns a pointer to the first
///				occurrence of c in s,
///			or NULL if c is not found.
char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (0);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}
