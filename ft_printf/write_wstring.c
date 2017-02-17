/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:05:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 00:33:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void				write_wstring(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	wchar_t		*draft;
	char		*utf8_draft;

	draft = ft_strdup(va_arg(ap, wchar_t *));
	if (!draft)
		draft = ft_strdup("(null)"); //wstrdup?
	//if (conversion->precision_set)
	//	apply_precision_wstr(conversion, &draft);
	if (conversion->width)
		apply_width_wchar(conversion, &draft);
	utf8_draft = ft_utf8strencode(draft);
	ft_putstr(utf8_draft);
	format->chars_written += ft_wstrlen(draft);
	return ;
}
