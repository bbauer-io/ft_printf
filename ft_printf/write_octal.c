/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:53:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 15:14:09 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_octal(t_conversion *conversion, va_list ap, t_format
																		*format)
{
	char	*draft;

	if (conversion && format)
		draft = ft_itoa_base(va_arg(ap, int), 8);
	format->chars_written += ft_strlen(draft);
	ft_putstr(draft);
}
