/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:12:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/30 09:36:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Just a message to notify the user than some invalid character appeared after
** '.' (should only be digits);
*/

static int		precision_not_valid_error_msg(t_format *format)
{
	ft_putstr_fd("ft_printf ERROR: detected '.' char but no valid precision \
			value followed! Only digits (0-9) are valid! Format string index: "
			, 2);
	ft_putnbr_fd(format->index, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

/*
** The first char has tested as '-' so we skip past that and consecutive digits.
*/

static int		treat_negative_precision_as_none(t_conversion *conversion,
												t_format *format)
{
	conversion->precision = 0;
	format->index++;
	while (ft_isdigit(format->str[format->index]))
		format->index++;
	return (GOOD);
}

/*
** This function will look for a precision value in the format string and store
** it if present.
*/

int				read_precision(t_conversion *conversion, va_list ap,
												t_format *format)
{
	if (format->str[format->index] == '.')
	{
		format->index++;
		if (format->str[format->index] == '-')
			return (treat_negative_precision_as_none(conversion, format));
		if (format->str[format->index] == '*')
		{
			conversion->width = va_arg(ap, unsigned int);
			conversion->precision_set = 1;
			format->index++;
			return (GOOD);
		}
		if (ft_isdigit(format->str[format->index]))
		{
			conversion->precision = ft_atoi(&format->str[format->index]);
			conversion->precision_set = 1;
			while (ft_isdigit(format->str[format->index]))
				format->index++;
			return (GOOD);
		}
		return (precision_not_valid_error_msg(format));
	}
	return (GOOD);
}
