/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:36 by itjimene          #+#    #+#             */
/*   Updated: 2025/03/01 17:41:15 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_is_float(const char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
