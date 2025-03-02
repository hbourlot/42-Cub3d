/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:25:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/02 19:29:43 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/// @brief Returns a pointer to a static split metadata structure.
/// @return Pointer to the static t_split_meta structure.
t_split_meta	*split_metadata(void)
{
	static t_split_meta	meta_data;

	return (&meta_data);
}
