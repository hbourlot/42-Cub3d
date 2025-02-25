/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:41:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:46 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static int	get_line_length(char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		if (src[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_strljoin(char *src1, char *src2)
{
	char	*temp;
	char	*result;
	int		i;

	if (!src1 && src2[0] == '\0')
		return (NULL);
	temp = malloc(sizeof(char) * get_line_length(src1) + get_line_length(src2)
			+ 1);
	if (!temp)
		return (NULL);
	result = temp;
	i = 0;
	while (src1 && src1[i])
		*temp++ = src1[i++];
	free(src1);
	i = 0;
	while (src2 && src2[i])
	{
		*temp++ = src2[i];
		if (src2[i] == '\n')
			break ;
		i++;
	}
	*temp = '\0';
	return (result);
}

static int	set_buffer(char *buffer)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (buffer[i])
	{
		if (k == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			k = 1;
		buffer[i++] = 0;
	}
	buffer[j] = '\0';
	return (k);
}

char	*get_next_line(int fd)
{
	char		*rest;
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (BUFFER_SIZE < 1)
		return (NULL);
	bytes = 42;
	rest = NULL;
	while (bytes != 0)
	{
		if (buffer[0] == 0)
			bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (rest)
				free(rest);
			return (NULL);
		}
		rest = ft_strljoin(rest, buffer);
		if (set_buffer(buffer) == 1)
			return (rest);
	}
	return (rest);
}
