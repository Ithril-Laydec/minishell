/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:41:08 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:45:03 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_precision(t_vars *vars)
{
	int	digits;

	if (*vars->format == '.')
	{
		vars->format++;
		vars->flags->precision = ft_atoi(vars->format);
		digits = ft_get_digits_len(vars->flags->precision);
		while (ft_isdigit(*vars->format))
			vars->format++;
	}
}
