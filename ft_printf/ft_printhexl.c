/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:41 by aternero          #+#    #+#             */
/*   Updated: 2024/06/13 21:18:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexl(unsigned int nb)
{
	int		value;
	char	*hex;

	hex = "0123456789abcdef";
	value = 0;
	if (nb >= 16)
	{
		value = value + ft_printhexl(nb / 16);
		value = value + ft_printhexl(nb % 16);
	}
	else
	{
		write(1, &hex[nb], 1);
		value = value + 1;
	}
	return (value);
}
