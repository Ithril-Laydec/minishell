/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:41 by aternero          #+#    #+#             */
/*   Updated: 2024/06/13 21:18:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexu(unsigned int nb)
{
	int		value;
	char	*hex;

	hex = "0123456789ABCDEF";
	value = 0;
	if (nb >= 16)
	{
		value = value + ft_printhexu(nb / 16);
		value = value + ft_printhexu(nb % 16);
	}
	else
	{
		write(1, &hex[nb], 1);
		value = value + 1;
	}
	return (value);
}
