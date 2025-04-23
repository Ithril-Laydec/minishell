/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:37:10 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 20:19:05 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_c(t_vars *vars)
{
	vars->types->char_arg = va_arg(vars->args, int);
	process_pre_flags(vars);
	ft_putchar_fd(vars->types->char_arg, 1);
	process_post_flags(vars);
	vars->printed_bytes++;
}
