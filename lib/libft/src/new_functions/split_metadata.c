/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:25:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 08:32:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

t_split_meta	*split_metadata( void )
{
	static t_split_meta	meta_data;

	return (&meta_data);
}
