/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:56:09 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 18:14:34 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		get_signed_int_arg(t_conversion *conversion, va_list ap)
{
	intmax_t	nbr;

	if (conversion->length == HH)
		nbr = (signed char)va_arg(ap, int);
	if (conversion->length == H || conversion->length == DEFAULT)
		nbr = va_arg(ap, int);
	if (conversion->length == LL)
		nbr = va_arg(ap, long long);
	if (conversion->length == L)
		nbr = va_arg(ap, long);
	if (conversion->length == J)
		nbr = va_arg(ap, intmax_t);
	if (conversion->length == Z)
		nbr = va_arg(ap, size_t);
	return (nbr);
}


// PRETTY SURE I NEED INTMAX ITOA && PUTNBR
void				write_signed_int(t_conversion *conversion, va_list ap,
															t_format *format)
{
	intmax_t	nbr;
	char		*draft;

	nbr = get_signed_int_arg(conversion, ap);
	draft = ft_itoa(nbr);
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if (nbr >= 0 &&
	(conversion->flags.pos_values_begin_w_space || conversion->flags.show_sign))
		apply_prefix(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	return ;
}
