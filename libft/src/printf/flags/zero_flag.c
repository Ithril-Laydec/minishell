/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:10:13 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:51:10 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	zero_flag(t_vars *vars)
{
	int	value;
	int	len;

	len = get_printable_len(vars) - vars->flags->printed_minus;
	if (vars->flags->precision != -1 && vars->flags->precision >= len)
	{
		if (vars->flags->type != 's')
			len -= (len - vars->flags->precision);
		if (vars->types->int_arg < 0)
			len++;
	}
	value = vars->flags->zero;
	while (value - len > 0)
	{
		if (vars->flags->precision != -1)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
		value--;
		vars->printed_bytes++;
	}
}
