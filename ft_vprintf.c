/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:16:21 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/28 07:56:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints a '%' when "%%" has appeared in the format string.
*/

int			double_percent(t_format *format)
{
	if (format->str[format->index] == '%')
	{
		ft_putchar('%');
		format->index++;
		format->chars_written++;
		return (1);
	}
	return (0);
}

/*
** Calls function to check for "%%", if not that, then we go on to decipher the
** symbols and convert the variable into the specified formats for printing.
*/

void		print_var(t_format *format, va_list ap)
{
	t_conversion	conversion;

	if (double_percent(format))
		return ;
	ft_bzero(&conversion, sizeof(t_conversion));
	if (read_conversion_substr(&conversion, ap, format) == GOOD
			&& verify_flag_compatibility(&conversion, format) == GOOD)
		write_conversion_substr(&conversion, ap, format);
	else if (format->str[format->index] == '%')
	{
		ft_putchar('%');
		format->index++;
		format->chars_written++;
	}

/*
**  THIS CODE WAS FOR TESTING THE FIRST STAGES
**	if (double_percent(format))
**		return ;
**	if (format->str[format->index] == 'd')
**		format->chars_written += ft_putstr(ft_itoa(va_arg(ap, int)));
**	return ;
*/
}

/*
** Prints each character and calls functions to convert variables to printable
** strings and print them when '%' is encountered in the format string.
** Returns the number of chars printed.
*/

int			ft_vprintf(const char *format, va_list ap)
{
	t_format	format_tracker;

	if (!format)
		return (0);
	ft_bzero(&format_tracker, sizeof(t_format));
	format_tracker.str = format;
	while (format_tracker.str[format_tracker.index] != '\0')
	{
		if (format_tracker.str[format_tracker.index] == '%')
		{
			format_tracker.index++;
			print_var(&format_tracker, ap);
		}
		else
		{
			ft_putchar(format_tracker.str[format_tracker.index++]);
			format_tracker.chars_written++;
		}
	}
	return (format_tracker.chars_written);
*}
