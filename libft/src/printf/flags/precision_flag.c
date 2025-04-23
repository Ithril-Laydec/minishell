/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:36 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:39:19 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	needed_zeros(t_vars *vars)
{
	if (vars->flags->type == 'd'
		|| vars->flags->type == 'i'
		|| vars->flags->type == 'u'
		|| vars->flags->type == 'x'
		|| vars->flags->type == 'X')
		return (1);
	return (0);
}

void	precision_flag(t_vars *vars)
{
	int	len;
	int	value;

	value = vars->flags->precision;
	if (vars->flags->type == 'd' || vars->flags->type == 'i')
		len = count_digits_in_integer(vars->types->int_arg);
	if (vars->flags->type == 'u')
	{
		len = count_digits_in_unsigned(vars->types->ull_arg);
		if (vars->types->ull_arg == 0 && vars->flags->precision == 0)
			len = 0;
	}
	if (vars->flags->type == 'x' || vars->flags->type == 'X')
		len = count_digits_in_hex(vars->types->ull_arg);
	if (needed_zeros(vars))
	{
		while (value > len)
		{
			ft_putchar_fd('0', 1);
			value--;
			vars->printed_bytes++;
		}
	}
}
