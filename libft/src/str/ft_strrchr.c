/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:36:15 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	c = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	str += i;
	while (i > -1)
	{
		if (*str == c)
			return (str);
		str--;
		i--;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
