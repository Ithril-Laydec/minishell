/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:01:23 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	aux;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		aux = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = aux;
		i++;
	}
	return (str);
}
