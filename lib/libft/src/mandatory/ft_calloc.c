/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:29:10 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:37:42 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates memory for an array of nmemb elements of size bytes each,
///	and initializes the memory to zero.
/// @param nmemb Number of elements to allocate.
/// @param size Size of each element.
/// @return Pointer to the allocated memory, or NULL if allocation fails.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = (void *)malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (nmemb * size));
	return (temp);
}
