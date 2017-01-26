/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:12:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/26 09:12:27 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_precision(t_conversion *conversion, va_list ap, t_format *format)
{
	size_t		counter;
	char		*ascii_nbr;

	if (format->str[format->index] == '.')
	{
		format->index++;
		if (format->str[format->index] == '*')
		{
			conversion->width = va_arg(ap, unsigned int);
			format->index++;
		}
		else
		{
			counter = 0;
			while (ft_isdigit(format->str[format->index]))
				counter++;
			format->index += counter;
			ascii_nbr = ft_strndup(&format->str[format->index], counter);
			conversion->precision = ft_atoi(ascii_nbr);
			ft_memdel((void **)&ascii_nbr);
		}
	}
	return (GOOD);
}
