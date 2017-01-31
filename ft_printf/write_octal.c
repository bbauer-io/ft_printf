/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:53:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 11:54:04 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_octal(t_conversion *conversion, va_list ap, t_format
																		format)
{
	ft_putstr(ft_itoa_base(va_list(ap, int), 8));
}
