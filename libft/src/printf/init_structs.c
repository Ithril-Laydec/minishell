/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:09:14 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/23 20:00:31 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_types(t_vars *vars)
{
	vars->types = malloc(sizeof(t_types));
	if (!vars->types)
		return (0);
	vars->types->ull_arg = 0;
	vars->types->int_arg = 0;
	vars->types->char_arg = 0;
	vars->types->str_arg = NULL;
	return (1);
}

int	init_flags(t_vars *vars)
{
	vars->flags = malloc(sizeof(t_flags));
	if (!vars->flags)
		return (0);
	vars->flags->type = 0;
	vars->flags->zero = 0;
	vars->flags->minus = 0;
	vars->flags->plus = 0;
	vars->flags->space = 0;
	vars->flags->hash = 0;
	vars->flags->precision = 0;
	vars->flags->width = 0;
	vars->flags->printed_minus = 0;
	return (1);
}

int	init_vars(t_vars **vars, char const *format, va_list args)
{
	*vars = malloc(sizeof(t_vars));
	if (!*vars)
		return (0);
	(*vars)->format = format;
	(*vars)->f_index = 0;
	(*vars)->printed_bytes = 0;
	if (!(init_flags(*vars)) || !(init_types(*vars)))
	{
		free(*vars);
		return (0);
	}
	va_copy((*vars)->args, args);
	return (1);
}

void	clear_flags(t_vars *vars)
{
	vars->flags->zero = -1;
	vars->flags->minus = -1;
	vars->flags->plus = -1;
	vars->flags->space = -1;
	vars->flags->hash = -1;
	vars->flags->precision = -1;
	vars->flags->width = -1;
	vars->flags->type = 0;
	vars->flags->printed_minus = 0;
	vars->flags->null_str = 0;
}

void	clear_types(t_vars *vars)
{
	vars->types->ull_arg = 0;
	vars->types->char_arg = 0;
	vars->types->str_arg = 0;
	vars->types->int_arg = 0;
}
