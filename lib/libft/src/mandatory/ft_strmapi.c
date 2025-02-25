/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:23:04 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:40:53 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Applies a function to each character of a string
///			to create a new string.
/// @param s The input string.
/// @param f The function to apply to each character.
/// @return The new string created by applying f to each character of s.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*temp;

	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			temp[i] = f(i, (char)s[i]);
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
