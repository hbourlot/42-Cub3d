/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:44:28 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/09 17:38:29 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculates the number of digits in an integer `nbr`.
/// @param nbr The integer whose length is to be calculated.
/// @return Number of digits in `nbr`.
int	ft_nbr_len(long nbr)
{
	if (nbr < 0)
		return (ft_nbr_len(-nbr) + 1);
	if (nbr > 9)
		return (ft_nbr_len(nbr / 10) + 1);
	return (1);
}
