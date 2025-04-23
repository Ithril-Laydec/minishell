/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pre_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:43:42 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 12:04:02 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_pre_flags(t_vars *vars)
{
	if (vars->flags->plus != -1)
		plus_flag(vars);
	else if (vars->flags->space > -1)
		space_flag(vars);
	if (vars->flags->width > 0 && vars->flags->minus == -1)
		width_flag(vars);
	if (vars->flags->zero != -1 && vars->flags->precision != -1)
	{
		if (vars->flags->zero != -1)
			zero_flag(vars);
		print_minus(vars);
		if (vars->flags->precision > -1)
			precision_flag(vars);
	}
	else
	{
		print_minus(vars);
		if (vars->flags->zero != -1)
			zero_flag(vars);
		if (vars->flags->precision > -1)
			precision_flag(vars);
	}
	if (vars->flags->hash > -1)
		hash_flag(vars);
}
