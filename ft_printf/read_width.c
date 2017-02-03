/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:11:52 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/03 11:49:21 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Read specified width, get va_arg if the width is a * (specified in arguments
** instead of in the format string).
*/

/*
** I am wondering if I need a new atoi that returns an Unsigned int here...
*/

int			read_width(t_conversion *conversion, va_list ap, t_format *format)
{
	if (format->str[format->index] == '*')
	{
		conversion->width = va_arg(ap, unsigned int);
		format->index++;
	}
	else if (ft_isdigit(format->str[format->index]))
	{
		conversion->width = ft_atoi(&format->str[format->index]);
		while (ft_isdigit(format->str[format->index]))
			format->index++;
	}
	return (GOOD);
}
