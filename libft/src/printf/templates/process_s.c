/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:57:11 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 12:17:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	relevant_flags(t_vars *vars)
{
	if ((vars->flags->precision != -1 && vars->flags->precision >= 6)
		|| vars->flags->precision == -1)
		return (1);
	return (0);
}

void	process_s(t_vars *vars)
{
	vars->types->str_arg = va_arg(vars->args, char *);
	if (!vars->types->str_arg)
		vars->flags->null_str = 1;
	process_pre_flags(vars);
	if (!vars->types->str_arg && relevant_flags(vars))
	{
		ft_putnstr("(null)", 1, 6);
		vars->printed_bytes += 6;
	}
	else if (vars->types->str_arg && vars->flags->precision != -1
		&& ft_strlen(vars->types->str_arg) > 0)
	{
		ft_putnstr(vars->types->str_arg, 1, vars->flags->precision);
		if (vars->flags->precision < (int)ft_strlen(vars->types->str_arg))
			vars->printed_bytes += vars->flags->precision;
		else
			vars->printed_bytes += ft_strlen(vars->types->str_arg);
	}
	else if (vars->types->str_arg)
	{
		ft_putstr_fd(vars->types->str_arg, 1);
		vars->printed_bytes += ft_strlen(vars->types->str_arg);
	}
	process_post_flags(vars);
}
