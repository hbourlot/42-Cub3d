/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:37:14 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/08 14:35:02 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Writes a single character `c` to the specified file
///				descriptor `fd`.
/// @param c The character to be written.
/// @param fd The file descriptor where the character should be written.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
