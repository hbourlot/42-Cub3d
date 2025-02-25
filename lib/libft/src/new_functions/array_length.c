/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:09:20 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/09 16:46:55 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of elements in a null-terminated
 * 		array of strings.
 *
 * This function iterates through each string in the provided
 * 		array `src`, counting the number of valid string elements
 * 		until it encounters a `NULL` pointer.
 * 		If the input array is `NULL` or the first element of the
 * 		array is `NULL`, the function returns `-1` to indicate
 * 		an error or invalid input.
 *
 * @param src A pointer to a null-terminated array of strings.
 * @return The number of elements in the array, or -1 if the
 * 			input is invalid.
 */
int	array_length(char **src)
{
	int	i;

	i = 0;
	if (!src || !*src)
		return (-1);
	while (src[i])
		i++;
	return (i);
}
