/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:00:19 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/28 17:24:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Removes the first occurrence of a substring from a source string.
/// @param source The original string from which the substring will be removed.
/// @param to_remove The substring to remove from the source string.
/// @return A newly allocated string with the substring removed,
///				or NULL if allocation fails or input is invalid.
char	*remove_substring(const char *source, char *to_remove)
{
	char	*pos;
	size_t	len;
	size_t	prefix_len;
	char	*new_source;

	if (!source || !to_remove)
		return (NULL);
	pos = ft_strstr(source, to_remove);
	if (!pos)
		return (ft_strdup(source));
	len = ft_strlen(source) - ft_strlen(to_remove);
	if (len == 0)
		return (ft_strdup(""));
	new_source = malloc(len + 1);
	if (!new_source)
		return (NULL);
	prefix_len = pos - source;
	ft_strncpy(new_source, source, prefix_len);
	ft_strcpy(new_source + prefix_len, pos + ft_strlen(to_remove));
	return (new_source);
}
