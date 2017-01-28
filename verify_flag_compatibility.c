/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag_harmony.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:03:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/28 10:50:21 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pos_values_begin_space_correction(t_conversion *conversion,
															t_format *format)
{
	if (conversion->flags.pos_values_begin_w_space
			&& conversion->flags.show_sign)
	{
		ft_putendl_fd("Flag ' ' is ignored when flag '+' is present", 2);
		ft_putstr_fd("See format string index: ", 2);
		ft_putnbr_fd(format->index, 2);
		ft_putchar_fd('\n', 2);
		conversion->flags.pos_values_begin_w_space = 0;
	}
}


static void			pad_zeros_flag_correction(t_conversion *conversion,
															t_format *format)
{
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->flags.left_justify)
		{
			ft_putendl_fd("flag '0' is ignored when flag '-' is present", 2);
			conversion->flags.pad_with_zeros = 0;
			ft_putstr_fd("see format string index ", 2);
			ft_putnbr_fd(format->index, 2);
			ft_putchar_fd('\n', 2);
		}
		else if (conversion->precision_set)
		{
			ft_putstr_fd("flag '0' is ignored when precision is used with %"
					, 2);
			ft_putchar_fd(format->str[format->index], 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("see format string index ", 2);
			ft_putnbr_fd(format->index, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	return ;
}

static int			precision_is_settable(t_conversion *conversion,
															t_format *format)
{
	if (conversion->precision_set
			&& ((conversion->specifier == CHAR && conversion->length >= L)
			|| conversion->specifier == POINTER))
	{
		ft_putstr_fd("ft_printf ERROR: precision is not a valid option with %"
				, 2);
		ft_putchar_fd(format->str[format->index], 2);
		if (format->str[format->index] == 'c')
			ft_putstr_fd(" and length modifier 'l'!", 2);
		ft_putstr_fd("see format string index ", 2);
		ft_putnbr_fd(format->index, 2);
		ft_putchar_fd('\n', 2);
		return (ERROR);
	}
	return (GOOD);
}

static int			pointer_size_specified(t_conversion *conversion,
															t_format *format)
{
	if (conversion->specifier == POINTER && conversion->length != DEFAULT)
	{
		ft_putstr_fd("ft_printf ERROR: A length flag ('l', 'll', 'h', 'hh', \
				'j', 'z') cannot be used on a pointer type argument. See \
				format string index: ", 2);
		ft_putnbr_fd(format->index, 2);
		ft_putchar_fd('\n', 2);
		return (ERROR);
	}
	return (GOOD);
}

int					verify_flag_compatibility(t_conversion *conversion,
														t_format *format)
{
	format->index--;
	pos_values_begin_space_correction(conversion, format);
	pad_zeros_flag_correction(conversion, format);
	if (precision_is_settable(conversion, format) == ERROR)
		return (ERROR);
	if (pointer_size_specified(conversion, format) == ERROR)
		return (ERROR);
	if (verify_flag_compatibility_continued(conversion, format) == ERROR)
		return (ERROR);
	format->index++;
	return (GOOD);
}
