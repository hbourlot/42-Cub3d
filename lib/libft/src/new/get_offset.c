/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:14:19 by hbourlot          #+#    #+#             */
/*   Updated: 2025/01/06 20:41:47 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Function to calculate the offset of a struct member
/// @param struct_ptr Pointer to the struct
/// @param member_ptr Pointer to the struct member
/// @return Offset in bytes from the start of the struct to the member
size_t	get_offset(void *struct_ptr, void *member_ptr)
{
	return ((size_t)((char *)member_ptr - (char *)struct_ptr));
}
