/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:15:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/16 11:44:51 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares a string `s1` with an array of strings `compers`.
/// @param s1 The string to compare.
/// @param compers Array of strings to compare against, terminated by NULL.
/// @param idx_found Pointer to store the index of the matching string,
///			 or -1 if no match.
/// @return 0 if a match is found; -1 otherwise.
int	ft_strcmps(const char *s1, const char *compers[])
{
	size_t			j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (!s1 || !compers)
		return (-1);
	j = -1;
	while (compers[++j])
	{
		ss1 = (unsigned char *)s1;
		ss2 = (unsigned char *)compers[j];
		while (*ss1 && *ss2 && *ss1 == *ss2)
		{
			ss1++;
			ss2++;
		}
		if (!*ss2)
			return (0);
	}
	return (-1);
}
