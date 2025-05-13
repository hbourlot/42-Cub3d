/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_longer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:35:56 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/24 07:36:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares the lengths of two strings to determine if the
// 			first is longer than the second.
/// @param str1 The first string to compare.
/// @param str2 The second string to compare.
/// @return Returns 1 if the length of str1 is greater than the
///			length of str2, otherwise returns 0.
int	is_str_longer(char *src1, char *src2)
{
	return (ft_strlen(src1) > ft_strlen(src2));
}
