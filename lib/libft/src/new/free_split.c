/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:47:52 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/06 21:54:45 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Frees the memory allocated for the array of strings.
/// @param split The array of strings to free.
void	free_split(char **split)
{
	int	ctd;

	ctd = 0;
	if (!split || !*split)
		return ;
	while (split[ctd])
		free(split[ctd++]);
	free(split);
}
