/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:02:35 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:50:39 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_flag(t_vars *vars)
{
	int	value;
	int	len;

	len = get_printable_len(vars);
	value = vars->flags->width;
	while (value - len > 0)
	{
		ft_putchar_fd(' ', 1);
		vars->printed_bytes++;
		value--;
	}
}
