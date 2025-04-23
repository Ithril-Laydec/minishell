/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:21:38 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 20:12:26 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	space_flag(t_vars *vars)
{
	if (vars->flags->space && vars->types->int_arg >= 0
		&& (vars->flags->type == 'd' || vars->flags->type == 'i'))
	{
		ft_putchar_fd(' ', 1);
		vars->printed_bytes++;
	}
}
