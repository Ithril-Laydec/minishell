/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:44:21 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 17:18:15 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	analyze_hash(t_vars *vars)
{
	if (*vars->format == '#')
	{
		vars->flags->hash = 1;
		vars->format++;
	}
}
