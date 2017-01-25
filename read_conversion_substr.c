/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:41:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/24 16:41:54 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]specifier
*/

int			read_conversion_substr(t_conversion *conversion, va_list ap,
					t_format *format)
{
	if (read_flags(conversion, format) == GOOD
				&& read_width(conversion, ap, format) == GOOD
				&& read_precision(conversion, ap, format) == GOOD
				&& read_length(conversion, format) == GOOD
				&& read_specifier(conversion, format) == GOOD)
		return (GOOD);
	else
		return (ERROR);
}
