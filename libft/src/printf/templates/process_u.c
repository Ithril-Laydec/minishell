/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:12:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 01:18:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_u(t_vars *vars)
{
	int	printed;

	vars->types->ull_arg = va_arg(vars->args, unsigned int);
	process_pre_flags(vars);
	if (vars->types->ull_arg == 0 && vars->flags->precision == 0)
	{
		printed = 0;
	}
	else
		printed = ft_putnbr_base_fd(vars->types->ull_arg, "0123456789", 1);
	process_post_flags(vars);
	vars->printed_bytes += printed;
}
