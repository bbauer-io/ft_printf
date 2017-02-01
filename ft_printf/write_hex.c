/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:50:02 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 15:41:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_hex(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char	*draft;
	if (conversion && format)
		draft = ft_itoa_base(va_arg(ap, int), 16);
	if (conversion->specifier == HEX_LOWER)
		ft_tolower_str(draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
}
