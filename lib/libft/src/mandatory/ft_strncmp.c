/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:40:05 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:33:43 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares the first n characters of two strings.
/// @param s1 The first string to compare.
/// @param s2 The second string to compare.
/// @param n The maximum number of characters to compare.
/// @return An integer less than, equal to, or greater than zero if s1 is found,
///	respectively, to be less than, to match, or be greater than s2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*ss1 && *ss2 && *ss1 == *ss2 && i < n - 1)
	{
		ss1++;
		ss2++;
		i++;
	}
	return (*ss1 - *ss2);
}
