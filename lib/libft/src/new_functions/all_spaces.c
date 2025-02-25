/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:41 by joralves          #+#    #+#             */
/*   Updated: 2025/02/20 14:48:57 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	all_spaces(const char *src)
{
	size_t	i;

	i = 0;
	if (!src || *src == '\0')
		return (false);
	while (src[i])
	{
		if (!ft_isspaces(src[i]))
			return (false);
		i++;
	}
	return (true);
}
