/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:19:32 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set && ft_strlen(set) != 0)
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
