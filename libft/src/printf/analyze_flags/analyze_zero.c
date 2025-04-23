/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:47:11 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:44:19 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_zero(t_vars *vars)
{
	int	digits;

	if (*vars->format == '0')
	{
		vars->format++;
		if (*vars->format == '0')
		{
			while (*vars->format == '0')
				vars->format++;
			vars->flags->zero = 0;
			return ;
		}
		vars->flags->zero = ft_atoi(vars->format);
		digits = ft_get_digits_len(vars->flags->zero);
		while (digits-- && vars->flags->zero)
			vars->format++;
	}
}
