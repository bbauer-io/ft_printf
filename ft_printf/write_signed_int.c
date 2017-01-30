/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:56:09 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/30 11:24:13 by bbauer           ###   ########.fr       */
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

void				write_signed_int(t_conversion *conversion, va_list ap,
															t_format *format)
{
	intmax_t	nbr;

	if (format)
	{
		nbr = get_signed_int_arg(conversion, ap);
		ft_putnbr(nbr);
	}
	return ;
}