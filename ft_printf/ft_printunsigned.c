/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:41 by aternero          #+#    #+#             */
/*   Updated: 2024/06/25 21:28:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_continueun(unsigned int nb)
{
	int	value;

	value = 0;
	if (nb >= 10)
		value = value + ft_continueun(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
	value = value + 1;
	return (value);
}

int	ft_printunsigned(unsigned int nb)
{
	int		value;

	value = 0;
	if (nb == 2147483648)
	{
		write(1, "2147483648", 10);
		value = value + 10;
	}
	else if (nb >= 0)
		value = value + ft_continueun(nb);
	return (value);
}
