/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:56:09 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/03 20:30:37 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static char			get_sign(**draft)
{
	char		sign;

	sign = '\0';
	while ((*draft)[i] != 0)
	{
		if ((*draft)[i] == '-')
			sign = '-';
		else if ((*draft)[i] == '+')
			sign = '+';
	}
	return (sign);
}


static void			fix_sign_placement(t_conversion *conversion, char **draft)
{
	int			i;
	char		sign;

	i = 0;
	if ((sign = get_sign(draft)))
		while ((*draft)[i] != '\0' && (*draft)[i] != sign)
			i++;
		if (
}
*/
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
	char		*draft;

	nbr = get_signed_int_arg(conversion, ap);
	if (!nbr && conversion->precision_set)
		draft = ft_strdup("");
	else
		draft = ft_itoa_base_intmax(nbr, 10);
	if (nbr < 0)
		conversion->int_is_negative = 1;
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (nbr >= 0 &&
	(conversion->flags.pos_values_begin_w_space || conversion->flags.show_sign))
		apply_prefix(conversion, &draft);
/*	if (conversion->int_is_negative)
		fix_prefix(draft)*/
	if (conversion->width)
		apply_width(conversion, &draft);
/*	fix_sign_placement(conversion, draft);
*/	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
	return ;
}
