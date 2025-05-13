/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:00 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/26 09:42:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts a string representation of a number to an integer.
/// @param nptr Pointer to the string to be converted.
/// @return The converted integer.
long	ft_atol(const char *nptr)
{
	int		tot;
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	tot = 0;
	while ((nptr[tot] >= 9 && nptr[tot] <= 13) || nptr[tot] == ' ')
		tot++;
	if (nptr[tot] == '+' || nptr[tot] == '-')
	{
		if (nptr[tot] == '-')
			sign = -1;
		tot++;
	}
	while (nptr[tot] >= '0' && nptr[tot] <= '9')
	{
		number = (number * 10) + nptr[tot] - '0';
		tot++;
	}
	return (number * sign);
}
