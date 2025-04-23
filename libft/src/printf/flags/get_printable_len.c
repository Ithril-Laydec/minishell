/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printable_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:20:46 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/24 10:50:18 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_base_len(t_vars *vars)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	if (vars->flags->type == 'u')
		tmp = ft_lotoa_base(vars->types->ull_arg, "0123456789");
	else if (vars->flags->type == 'p' || vars->flags->type == 'x')
		tmp = ft_lotoa_base(vars->types->ull_arg, "0123456789abcdef");
	else if (vars->flags->type == 'X')
		tmp = ft_lotoa_base(vars->types->ull_arg, "0123456789ABCDEF");
	len = ft_strlen(tmp);
	if (vars->flags->type == 'p')
		len += 2;
	if (vars->flags->width != -1 && vars->flags->precision != -1
		&& vars->flags->precision > len)
		len += (vars->flags->precision - len);
	if (vars->types->ull_arg == 0 && vars->flags->precision == 0)
		len = 0;
	free(tmp);
	return (len);
}

static int	get_str_printable_len(t_vars *vars)
{
	int		len;

	if (!vars->types->str_arg && vars->flags->precision != -1
		&& vars->flags->precision < 6)
		len = 0;
	else if (!vars->types->str_arg)
		len = 6;
	else if (vars->flags->precision != -1
		&& vars->flags->precision < (int)ft_strlen(vars->types->str_arg))
		len = vars->flags->precision;
	else
		len = ft_strlen(vars->types->str_arg);
	return (len);
}

static int	get_d_i_len(t_vars *vars)
{
	int		len;

	len = count_digits_in_integer(vars->types->int_arg);
	if (vars->flags->width != -1 && vars->flags->precision != -1
		&& vars->flags->precision > len)
		len += (vars->flags->precision - len);
	if (vars->types->int_arg < 0)
		len++;
	if (vars->types->int_arg == 0 && vars->flags->precision == 0)
		len = 0;
	return (len);
}

int	get_printable_len(t_vars *vars)
{
	int		len;

	if (vars->flags->type == 'c')
		len = 1;
	else if (vars->flags->type == 's')
		len = get_str_printable_len(vars);
	else if (vars->flags->type == 'd' || vars->flags->type == 'i')
		len = get_d_i_len(vars);
	else if (vars->flags->type == 'u')
		len = get_base_len(vars);
	else if (vars->flags->type == 'p')
	{
		len = get_base_len(vars);
		if ((vars->flags->width != -1 || vars->flags->minus != -1)
			&& vars->types->ull_arg == 0)
			len = 5;
	}
	else if (vars->flags->type == 'x' || vars->flags->type == 'X')
		len = get_base_len(vars);
	else
		len = count_digits_in_integer(vars->types->ull_arg);
	return (len);
}
