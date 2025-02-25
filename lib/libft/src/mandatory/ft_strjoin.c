/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:25:11 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:34:06 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Concatenates two strings s1 and s2 into a newly allocated string.
/// @param s1 The first string to concatenate.
/// @param s2 The second string to concatenate.
/// @return A pointer to the newly allocated concatenated string,
///	or NULL if allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	len_s1;
	size_t	len_s2;
	char	*final;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!temp)
		return (NULL);
	final = temp;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (final);
}
