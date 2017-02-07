/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:32 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 14:39:32 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_string(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char	*draft;

	draft = ft_strdup(va_arg(ap, char *));
	if (!draft)
		draft = ft_strdup("(null)");
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	ft_putnbr(conversion->precision);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	return ;
}
