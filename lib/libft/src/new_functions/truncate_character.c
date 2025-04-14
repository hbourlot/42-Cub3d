/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:09:01 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/11 14:29:30 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Truncates all occurrences of the specified character
///			from the source string.
/// @param src The string to modify.
/// @param character The character to remove.
/// @return 0 on success, -1 if src is NULL.
int	truncate_character(char *src, const char character)
{
	int	i;
	int	j;

	i = 0;
	if (!src)
		return (-1);
	while (src[i])
	{
		if (src[i] == character)
		{
			j = i;
			while (src[j + 1])
			{
				src[j] = src[j + 1];
				j++;
			}
			src[j] = '\0';
			i = 0;
			continue ;
		}
		i++;
	}
	return (0);
}
