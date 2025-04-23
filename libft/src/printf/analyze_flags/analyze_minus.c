/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:39:32 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:45:11 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_minus(t_vars *vars)
{
	int	digits;

	if (*vars->format == '-')
	{
		vars->format++;
		if (*vars->format == '-')
		{
			while (*vars->format == '-')
				vars->format++;
			vars->flags->minus = 0;
			return ;
		}
		vars->flags->minus = ft_atoi(vars->format);
		digits = ft_get_digits_len(vars->flags->minus);
		while (digits-- && vars->flags->minus)
			vars->format++;
	}
}
