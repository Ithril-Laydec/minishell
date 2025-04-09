/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:26:10 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	move_forward(char *dest, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	move_backward(char *dest, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[n - i - 1] = src[n - i - 1];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*source;
	char			*destiny;

	if (src == NULL && dest == NULL)
		return (NULL);
	source = (char *)src;
	destiny = (char *)dest;
	if (dest > src)
		move_backward(destiny, source, n);
	else
		move_forward(destiny, source, n);
	return (dest);
}
