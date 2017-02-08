/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:50:02 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/08 14:25:06 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Apply precision, then prefix, then width(and justify from that function)
*/

#include "ft_printf.h"

static void			add_hex_prefix(char **draft)
{
	char	*temp;

	temp = *draft;
	*draft = ft_strnew(ft_strlen(*draft) + 2);
	**draft = '0';
	*(*draft + 1) = 'X';
	ft_strcpy(*draft + 2, temp);
	ft_memdel((void **)&temp);
	return ;
}

void				write_hex(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char		*draft;
	uintmax_t	value;

	value = get_unsigned_int_arg(conversion, ap);
	draft = ft_itoa_base_uintmax(value, 16);
	if (conversion->precision_set && conversion->specifier != POINTER)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if ((conversion->flags.hash && *draft != '0')
										|| conversion->specifier == POINTER)
		add_hex_prefix(&draft);
	if (conversion->flags.pos_values_begin_w_space
										|| conversion->flags.show_sign)
		apply_prefix(conversion, &draft);
	if (conversion->specifier == HEX_LOWER || conversion->specifier == POINTER)
		ft_tolower_str(draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
}
