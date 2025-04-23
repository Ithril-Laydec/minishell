/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 17:18:24 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_space(t_vars *vars)
{
	if (*vars->format == ' ')
	{
		vars->flags->space = 1;
		vars->format++;
	}
}
