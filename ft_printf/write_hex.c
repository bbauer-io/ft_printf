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
	draft = ft_itoa_base(value, 16);
	if (!*draft)
		draft = ft_strdup("0");
	if ((conversion->flags.hash && *draft != '0')
										|| conversion->specifier == POINTER)
		add_hex_prefix(&draft);
	if (conversion->specifier == HEX_LOWER || conversion->specifier == POINTER)
		ft_tolower_str(draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
}
