/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:03:35 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_ispace(const char *c)
{
	if (*c == ' ' || *c == '\t' || *c == '\n'
		|| *c == '\v' || *c == '\f' || *c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	negative;

	negative = 0;
	while (ft_ispace(str))
		str++;
	if (str[0] == '-')
		negative = 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (ft_isdigit(*str))
	{
		if (!negative)
			n = (n * 10) + (*str - '0');
		else
			n = (n * 10) - (*str - '0');
		str++;
	}
	return (n);
}
