/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:32 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 12:16:33 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	plus_flag(t_vars *vars)
{
	if (vars->types->ull_arg >= 0
		&& vars->types->int_arg >= 0
		&& vars->flags->printed_minus != 1)
	{
		ft_putchar_fd('+', 1);
		vars->printed_bytes++;
	}
}
