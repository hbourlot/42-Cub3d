/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:02:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/06 15:11:23 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (ft_putstr("(null)"));
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}
