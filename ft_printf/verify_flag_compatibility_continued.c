/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag_compatibility_continued.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:05:27 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/28 10:32:32 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			hashtag_compatibility(t_conversion *conversion,
														t_format *format)
{
	if (conversion->flags.hash)
		if (!(conversion->specifier == HEX_LOWER
			|| conversion->specifier == HEX_UPPER
			|| conversion->specifier == OCTAL))
		{
			ft_putstr_fd("ft_printf ERROR: flag '#' cannot be used with %", 2);
			ft_putchar_fd(format->str[format->index], 2);
			ft_putstr_fd("! see format string index ", 2);
			ft_putnbr_fd(format->index, 2);
			ft_putchar_fd(format->str[format->index], 2);
			ft_putchar_fd('\n', 2);
			return (ERROR);
		}
	return (GOOD);
}

static int			zero_flag_compatibility(t_conversion *conversion,
														t_format *format)
{
	if (conversion->flags.pad_with_zeros)
		if (conversion->specifier == CHAR
				|| conversion->specifier == STRING
				|| conversion->specifier == POINTER)
		{
			ft_putstr_fd("ft_printf ERROR: pad with zeros flag '0' is not \
					compatible with specifier %", 2);
			ft_putchar_fd(format->str[format->index], 2);
			ft_putstr_fd("! See format string index: ", 2);
			ft_putnbr_fd(format->index, 2);
			ft_putchar_fd('\n', 2);
			return (ERROR);
		}
	return (GOOD);
}

static int			show_pos_flag_compatibility(t_conversion *conversion,
														t_format *format)
{
	if (conversion->flags.pos_values_begin_w_space
			|| conversion->flags.show_sign)
		if (conversion->specifier != S_DECIMAL)
		{
			ft_putstr_fd("ft_printf ERROR: flag '", 2);
			ft_putchar_fd(conversion->flags.show_sign ? '+' : ' ', 2);
			ft_putstr_fd("' is incompatible with specifier %", 2);
			ft_putchar_fd(format->str[format->index], 2);
			ft_putstr_fd("! See format string index: ", 2);
			ft_putnbr_fd(format->index, 2);
			ft_putchar_fd('\n', 2);
			return (ERROR);
		}
	return (GOOD);
}

int					verify_flag_compatibility_continued(t_conversion
												*conversion, t_format *format)
{
	if (hashtag_compatibility(conversion, format) == ERROR)
		return (ERROR);
	if (zero_flag_compatibility(conversion, format) == ERROR)
		return (ERROR);
	if (show_pos_flag_compatibility(conversion, format) == ERROR)
		return (ERROR);
	return (GOOD);
}
