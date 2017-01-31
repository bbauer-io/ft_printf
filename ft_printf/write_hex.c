/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:50:02 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 11:53:14 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_hex(t_conversion *conversion, va_list ap, t_format
																		format)
{
	ft_putstr(ft_itoa_base(va_list(ap, int), 16));
}
