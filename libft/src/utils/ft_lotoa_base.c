/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lotoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:00:32 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_lotoa_base(unsigned long long n, char *base)
{
	unsigned long long	len;
	char				*string;
	long				i;

	len = ft_strlen(base);
	i = 0;
	string = (char *)malloc(sizeof(char) * 33);
	if (!string)
		return (NULL);
	while (n >= len)
	{
		string[i] = base[n % len];
		n /= len;
		i++;
	}
	string[i] = base[n];
	string[i + 1] = '\0';
	return (ft_strrev(string));
}
