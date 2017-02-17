/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:58 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 02:42:12 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_char(t_conversion *conversion, va_list ap,
															t_format *format)
{
	char		*draft;

	if (conversion->flags.hash)
		return ;
	draft = ft_strnew(1);
	*draft = va_arg(ap, int);
	apply_width(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
}
