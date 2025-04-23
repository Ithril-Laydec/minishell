/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_post_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:43:42 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:13:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_post_flags(t_vars *vars)
{
	if (vars->flags->minus != -1)
		minus_flag(vars);
}
