/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:50:57 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:42:06 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Applies the function f to each character of the
///			string s along with its index.
/// @param s The string to iterate over.
/// @param f The function to apply to each character of s,
///			which takes as parameters the index of the character
///			and a pointer to the character.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (*s)
		{
			f(i, s);
			i++;
			s++;
		}
	}
}
