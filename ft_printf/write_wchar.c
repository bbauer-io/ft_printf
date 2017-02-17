/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:39:43 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 23:21:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_wchar(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	wchar_t		*draft;
	char		*utf8_draft;

	if (conversion->flags.hash)
		return ;
	else
	{
		draft = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		*draft = va_arg(ap, wint_t);
		draft[1] = '\0';
		apply_width_wchar(conversion, &draft);
		utf8_draft = ft_utf8strencode(draft);
		ft_putstr(utf8_draft);
		format->chars_written += (conversion->width > 1 ? conversion->width : 1);
	}
}
