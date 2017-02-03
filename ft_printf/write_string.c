/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:32 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/02 19:29:35 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_string(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char	*draft;

	if (conversion)
	{
		draft = va_arg(ap, char *);
		if (!draft)
			draft = ft_strdup("(null)");
		ft_putstr(draft);
		format->chars_written += ft_strlen(draft);
		return ;
	}
}
