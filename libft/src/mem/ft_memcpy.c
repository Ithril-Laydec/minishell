/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:10:51 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		d[n] = s[n];
	return (dest);
}
