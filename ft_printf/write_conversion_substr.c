/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_conversion_substr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 07:57:15 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 12:05:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_conversion_substr(t_conversion *conversion,
												va_list ap, t_format *format)
{
	if (conversion->specifier == S_DECIMAL)
		write_signed_int(conversion, ap, format);
//	if (conversion->specifier == U_DECIMAL)
//		write_unsigned_int(conversion, ap, format);
	if (conversion->specifier == HEX_UPPER
					|| conversion->specifier == HEX_LOWER)
		write_hex(conversion, ap, format);
//	if (conversion->specifier == OCTAL)
//		write_octal(conversion, ap, format);
//	if (conversion->specifier == POINTER)
//		write_hex(conversion, ap, format);
//	if (conversion->specifier == STRING)
//		write_string(conversion, ap, format);
//	if (conversion->specifier == CHAR)
//		write_char(conversion, ap, format);
	return ;
}
