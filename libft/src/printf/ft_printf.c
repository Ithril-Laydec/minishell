/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:50:39 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:51:47 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_vars(t_vars *vars)
{
	free(vars->flags);
	free(vars->types);
	free(vars);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	t_vars	*vars;
	int		printed_bytes;

	va_start(args, format);
	if (!init_vars(&vars, format, args))
		return (0);
	while (*vars->format)
	{
		if (*vars->format == '%')
		{
			vars->format++;
			process_argument(vars);
		}
		else
		{
			ft_putchar_fd(*vars->format, 1);
			vars->printed_bytes++;
		}
		vars->format++;
	}
	va_end(args);
	printed_bytes = vars->printed_bytes;
	free_vars(vars);
	return (printed_bytes);
}
