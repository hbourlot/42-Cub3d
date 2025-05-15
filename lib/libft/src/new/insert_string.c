/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:43:10 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/10 15:37:48 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Inserts a string into another string at a specified position.
/// @param dest The original string where another string will be inserted.
/// @param src The string to insert into dest.
/// @param idx_to_add The index in dest where src should be inserted.
/// @return A newly allocated string containing the result of the insertion,
///         or NULL if an error occurs (invalid parameters or
///			memory allocation failure).
char	*insert_string(char *dest, char *src, int idx_to_add)
{
	int		length_d;
	int		length_s;
	char	*new;

	if (!src || !dest)
		return (NULL);
	length_s = ft_strlen(src);
	length_d = ft_strlen(dest);
	if (idx_to_add > length_d)
		return (NULL);
	new = malloc(length_d + length_s + 1);
	ft_strncpy(new, dest, idx_to_add);
	ft_strncpy(new + idx_to_add, src, length_s);
	ft_strcpy(new + idx_to_add + length_s, dest + idx_to_add);
	return (new);
}
