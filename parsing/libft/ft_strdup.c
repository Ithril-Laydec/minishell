/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:42:09 by aternero          #+#    #+#             */
/*   Updated: 2025/05/14 19:46:11 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

char	*ft_strdup(const char *s)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, ft_strlen((char *)s) + 1);
	return (new_str);
}
