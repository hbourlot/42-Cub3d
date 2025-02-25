/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:45:31 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/26 17:11:38 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculates the length of the number `nbr` when
///			represented as a string.
/// @param nbr The number to calculate the length of.
/// @return The length of the number `nbr`.
static int	ft_nbr_len1(long nbr)
{
	if (nbr < 0)
		return (ft_nbr_len1(-nbr) + 1);
	if (nbr > 9)
		return (ft_nbr_len1(nbr / 10) + 1);
	return (1);
}

/// @brief Converts a long integer `nbr` into a string representation.
/// @param nbr The number to be converted.
/// @return A dynamically allocated string representing the number `nbr`,
///			or NULL if allocation fails.
char	*ft_itoa_iter(long nbr)
{
	int		len;
	char	*temp;

	len = ft_nbr_len1(nbr);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	if (nbr < 0)
	{
		temp[0] = '\0';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		temp[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (temp);
}
