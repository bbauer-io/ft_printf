/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:03 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/02 19:42:00 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_width_str(t_conversion *conversion, char **draft)
{
	if (conversion || draft)
		return ;
	return ;
}

/*
** ints and hex are padded with leading zeros if precision is larger than the
** number of digits needed to display the number, but a smaller precision will
** never truncate the number.
*/

static void			apply_width_int(t_conversion *conversion, char **draft)
{
	char	*temp;
	int		i;

	if (ft_strlen(*draft) < conversion->width)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->width);
		i = 0;
		while (conversion->width > ft_strlen(temp) + i)
			(*draft)[i++] = (conversion->flags.pad_with_zeros ? '0' : ' ');
		ft_strcpy(&((*draft)[i]), temp);
		ft_memdel((void **)&temp);
	}
}

void				apply_width(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_width_str(conversion, draft);
	else
		apply_width_int(conversion, draft);
	return ;
}
