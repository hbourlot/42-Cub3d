/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:39:18 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/11 14:59:25 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Frees the memory allocated for the array of strings.
/// @param split The array of strings to free.
void	free_split(char **split)
{
	int	ctd;

	if (split == NULL)
		return ;
	ctd = 0;
	while (split[ctd])
	{
		free(split[ctd]);
		ctd++;
	}
	free(split);
}
