/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:26:52 by hbourlot          #+#    #+#             */
/*   Updated: 2024/12/09 16:19:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef CMP_OK
# define CMP_OK 0
#endif

/// @brief Sorts tokens in descending order of length.
/// @param tokens The array of tokens to sort.
static void	sort_tokens_by_length(const char *tokens[])
{
	int			i;
	int			j;
	const char	*temp;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			if (ft_strlen(tokens[j]) > ft_strlen(tokens[i]))
			{
				temp = tokens[i];
				tokens[i] = tokens[j];
				tokens[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/// @brief Skips tokens in the string and returns a pointer to the
///			 first non-token character.
/// @param src Pointer to the input string.
/// @param tokens The array of tokens to skip.
/// @return Pointer to the first non-token character.
static char	*skip_tokens(char *src, const char *tokens[])
{
	int	j;
	int	token_len;

	while (*src)
	{
		j = 0;
		while (tokens[j])
		{
			token_len = ft_strlen(tokens[j]);
			if (ft_strncmp(src, tokens[j], token_len) == CMP_OK)
			{
				src += token_len;
				j = -1;
			}
			j++;
		}
		if (j > 0)
			break ;
	}
	return (src);
}

/// @brief Counts the number of parts in the string split by tokens.
/// @param src The input string.
/// @param tokens The array of tokens to split by.
/// @return The number of parts found.
static void	count_parts(char *src, const char *tokens[], int *count)
{
	int	part_len;
	int	j;

	while (*src)
	{
		src = skip_tokens(src, tokens);
		if (*src)
		{
			(*count)++;
			part_len = -1;
			while (src[++part_len])
			{
				j = -1;
				while (tokens[++j])
				{
					if (ft_strncmp(&src[part_len], tokens[j],
							ft_strlen(tokens[j])) == CMP_OK)
						break ;
				}
				if (tokens[j])
					break ;
			}
			src += part_len;
		}
	}
}

/// @brief Extracts the next part of the string split by tokens.
/// @param src Pointer to the input string (will be updated).
/// @param tokens The array of tokens to split by.
/// @return The next extracted part of the string.
static char	*extract_part(char **src, const char *tokens[])
{
	char	*result;
	int		part_len;
	int		j;

	*src = skip_tokens(*src, tokens);
	part_len = 0;
	while ((*src)[part_len])
	{
		j = 0;
		while (tokens[j])
		{
			if (ft_strncmp(&(*src)[part_len], tokens[j],
				ft_strlen(tokens[j])) == CMP_OK)
				break ;
			j++;
		}
		if (tokens[j])
			break ;
		part_len++;
	}
	result = ft_substr(*src, 0, part_len);
	*src += part_len;
	return (result);
}

/// @brief Splits a string by multiple tokens into an array of strings.
/// @param src The input string.
/// @param tokens The array of tokens to split by.
/// @return A NULL-terminated array of strings resulting from the split.
char	**split_by_multiple_tokens(char *src, const char *tokens[])
{
	char	**split;
	int		parts;
	int		idx;

	if (!src || !tokens)
		return (NULL);
	parts = 0;
	sort_tokens_by_length(tokens);
	count_parts(src, tokens, &parts);
	split = malloc((parts + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	idx = -1;
	while (++idx < parts)
	{
		split[idx] = extract_part(&src, tokens);
		if (!split[idx])
		{
			free_split(split);
			return (NULL);
		}
	}
	split[idx] = NULL;
	return (split);
}
