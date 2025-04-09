/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && dst[dst_len + i] != '\n' && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (size <= dst_len)
		return (size + src_len);
	return (dst_len + src_len);
}
