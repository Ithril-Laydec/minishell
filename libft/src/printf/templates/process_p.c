/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:08:22 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 01:28:22 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_p(t_vars *vars)
{
	vars->types->ull_arg = va_arg(vars->args, unsigned long long);
	if (vars->types->ull_arg == 0)
	{
		process_pre_flags(vars);
		ft_putstr_fd("(nil)", 1);
		vars->printed_bytes += 5;
		process_post_flags(vars);
		return ;
	}
	process_pre_flags(vars);
	ft_putstr_fd("0x", 1);
	vars->printed_bytes += 2;
	vars->printed_bytes += ft_putnbr_base_fd(vars->types->ull_arg,
			"0123456789abcdef", 1);
	process_post_flags(vars);
}
