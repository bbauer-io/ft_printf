/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:25:50 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/02 19:25:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unsigned_int_arg(t_conversion *conversion, va_list ap)
{
	uintmax_t	nbr;

	if (conversion->length == HH)
		nbr = (unsigned char)va_arg(ap, int);
	if (conversion->length == H || conversion->length == DEFAULT)
		nbr = va_arg(ap, unsigned int);
	if (conversion->length == LL)
		nbr = va_arg(ap, unsigned long long);
	if (conversion->length == L)
		nbr = va_arg(ap, unsigned long);
	if (conversion->length == J)
		nbr = va_arg(ap, uintmax_t);
	if (conversion->length == Z)
		nbr = va_arg(ap, size_t);
	return (nbr);
}
