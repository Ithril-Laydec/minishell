/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:11 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 19:22:18 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	hash_flag(t_vars *vars)
{
	if (vars->flags->type == 'x' && vars->types->ull_arg != 0)
	{
		ft_putstr_fd("0x", 1);
		vars->printed_bytes += 2;
	}
	else if (vars->flags->type == 'X' && vars->types->ull_arg != 0)
	{
		ft_putstr_fd("0X", 1);
		vars->printed_bytes += 2;
	}
}
