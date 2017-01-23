/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:41:39 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/23 12:59:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]specifier
*/

int			orchestrate_conversion(t_conversion *conversion, va_list ap,
					t_format *format)
{
	if (examine_flags(conversion, format) == GOOD
				&& determine_width(conversion, ap, format) == GOOD
				&& determine_precision(conversion, ap, format) == GOOD
				&& determine_length(conversion, format) == GOOD
				&& determine_specifier(conversion, format) == GOOD)
		return (GOOD);
	else
		return (ERROR);
}
