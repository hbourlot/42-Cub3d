/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:16:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/14 19:41:32 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares two null-terminated strings lexicographically.
/// @param s1 Pointer to the first string.
/// @param s2 Pointer to the second string.
/// @return An integer less than, equal to, or greater than zero if s1 is found,
///         respectively, to be less than, to match, or be greater than s2.
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
