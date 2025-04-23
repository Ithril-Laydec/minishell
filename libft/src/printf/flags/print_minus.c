/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:03:18 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 20:19:35 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_minus(t_vars *vars)
{
	if (vars->types->int_arg < 0)
	{
		ft_putchar_fd('-', 1);
		vars->printed_bytes++;
		vars->flags->zero--;
		vars->flags->printed_minus = 1;
	}
}
