/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:22 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:50:48 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	minus_flag(t_vars *vars)
{
	int	value;
	int	len;

	if (vars->flags->width != -1 && vars->flags->minus == 0)
		vars->flags->minus = vars->flags->width;
	len = get_printable_len(vars);
	if (vars->flags->precision != -1 && vars->flags->type != 's'
		&& vars->flags->precision > len)
		len -= (len - vars->flags->precision);
	if (vars->flags->printed_minus)
		len++;
	value = vars->flags->minus;
	while (value - len > 0)
	{
		ft_putchar_fd(' ', 1);
		vars->printed_bytes++;
		value--;
	}
}
