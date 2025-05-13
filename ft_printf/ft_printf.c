/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:59:23 by aternero          #+#    #+#             */
/*   Updated: 2024/06/25 21:25:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typeformat(const char *format, int index, va_list arg)
{
	int		value;
	char	percent;

	value = 0;
	percent = '%';
	if (format[index] == '%')
	{
		write(1, &percent, 1);
		value = value + 1;
	}
	else if (format[index] == 'c')
		value = value + ft_printchar(va_arg(arg, int));
	else if (format[index] == 's')
		value = value + ft_printstr(va_arg(arg, char *));
	else if (format[index] == 'p')
		value = value + ft_printptr(va_arg(arg, uintptr_t));
	else if (format[index] == 'd' || format[index] == 'i')
		value = value + ft_printnbr(va_arg(arg, int));
	else if (format[index] == 'u')
		value = value + ft_printunsigned(va_arg(arg, unsigned int));
	else if (format[index] == 'x')
		value = value + ft_printhexl(va_arg(arg, unsigned int));
	else if (format[index] == 'X')
		value = value + ft_printhexu(va_arg(arg, unsigned int));
	return (value);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			index;
	int			value;

	index = 0;
	value = 0;
	va_start(arg, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			value = value + ft_typeformat(format, index, arg);
			index++;
		}
		else
		{
			value = value + write(1, &format[index], 1);
			index++;
		}
	}
	va_end(arg);
	return (value);
}
