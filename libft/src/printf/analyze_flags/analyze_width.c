/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:45:16 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 17:18:09 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_width(t_vars *vars)
{
	int	digits;

	if (ft_isdigit(*vars->format))
	{
		vars->flags->width = ft_atoi(vars->format);
		digits = ft_get_digits_len(vars->flags->width);
		while (digits-- && vars->flags->width)
			vars->format++;
	}
}
