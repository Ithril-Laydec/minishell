/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:26:21 by aternero          #+#    #+#             */
/*   Updated: 2024/06/25 21:27:11 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(uintptr_t ptr)
{
	int		value;
	char	*hex;

	hex = "0123456789abcdef";
	value = 0;
	if (ptr >= 16)
	{
		value = value + ft_printhex(ptr / 16);
		write(1, &hex[ptr % 16], 1);
		value = value + 1;
	}
	else
	{
		write(1, &hex[ptr], 1);
		value = value + 1;
	}
	return (value);
}

int	ft_printptr(uintptr_t ptr)
{
	size_t		value;

	value = 0;
	if (!ptr)
		return (ft_printstr("(nil)"));
	value += ft_printstr("0x");
	value += ft_printhex(ptr);
	return (value);
}
