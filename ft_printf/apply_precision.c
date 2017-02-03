/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:14:23 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/03 10:26:25 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_precision_str(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (conversion->precision < ft_strlen(*draft))
	{
		temp = *draft;
		*draft = ft_strndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

/*
** ints and hex are padded with leading zeros if precision is larger than the
** number of digits needed to display the number, but a smaller precision will
** never truncate the number.
*/

static void			apply_precision_int(t_conversion *conversion, char **draft)
{
	char	*temp;
	int		i;

	if (ft_strlen(*draft) < conversion->precision)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->precision);
		i = 0;
		while (conversion->precision > ft_strlen(temp) + i)
			(*draft)[i++] = '0';
		ft_strcpy(&((*draft)[i]), temp);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_precision_str(conversion, draft);
	else if (conversion->specifier != POINTER)
		apply_precision_int(conversion, draft);
	return ;
}
