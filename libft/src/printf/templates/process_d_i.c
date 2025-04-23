/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:10:17 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:45:15 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_d_i(t_vars *vars)
{
	int	printed;

	vars->types->int_arg = va_arg(vars->args, int);
	process_pre_flags(vars);
	if (vars->types->int_arg == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		printed = 10;
	}
	else if (vars->types->int_arg == 0 && vars->flags->precision == 0)
	{
		printed = 0;
	}
	else
	{
		if (vars->types->int_arg < 0)
			vars->types->int_arg *= -1;
		printed = ft_putnbr_fd(vars->types->int_arg, 1);
	}
	process_post_flags(vars);
	vars->printed_bytes += printed;
}
