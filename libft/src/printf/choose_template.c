/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_template.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:32:28 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 20:23:28 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_template(t_vars *vars)
{
	if (vars->flags->type == 'c')
		process_c(vars);
	else if (vars->flags->type == 's')
		process_s(vars);
	else if (vars->flags->type == 'p')
		process_p(vars);
	else if (vars->flags->type == 'd')
		process_d_i(vars);
	else if (vars->flags->type == 'i')
		process_d_i(vars);
	else if (vars->flags->type == 'u')
		process_u(vars);
	else if (vars->flags->type == 'x')
		process_x(vars);
	else if (vars->flags->type == 'X')
		process_x_upper(vars);
	else if (vars->flags->type == '%')
	{
		ft_putchar_fd('%', 1);
		vars->printed_bytes++;
	}
}
