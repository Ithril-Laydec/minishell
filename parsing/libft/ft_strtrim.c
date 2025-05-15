/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:52:18 by aternero          #+#    #+#             */
/*   Updated: 2025/05/15 12:55:58 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

static int	is_in_set(char c, char const *set)
{
	while (*set && ft_strlen((char *)set) != 0)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimed;

	start = 0;
	end = 0;
	len = ft_strlen((char *)s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (is_in_set(s1[len - end - 1], set))
		end++;
	if (len == start || len == end)
		return (ft_strdup(""));
	trimed = malloc(sizeof(char) * ((len - start - end) + 1));
	if (!trimed)
		return (NULL);
	ft_strlcpy(trimed, s1 + start, len - start - end + 1);
	trimed[len - start - end + 1] = '\0';
	return (trimed);
}
