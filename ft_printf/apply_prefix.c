/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:42:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 19:05:50 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_prefix(t_conversion *conversion, char **draft)
{
	int		i;
	char	prefix_char;
	char	*temp;

	prefix_char = conversion->flags.show_sign ? '+' : ' ';
	i = 0;
	while (!ft_isdigit((*draft)[i]) && (*draft)[i] != '\0')
		i++;
	if (i > 0 && (*draft)[i] != '0')
		i--;
	if ((*draft)[i] == '0' || (*draft)[i] == ' ')
		(*draft)[i] = prefix_char;
	else
	{
		temp = *draft;
		*draft = ft_strnew(ft_strlen(*draft));
		**draft = prefix_char;
		ft_strcpy(&(*draft)[1], temp);
		ft_memdel((void **)&temp);
	}
	return ;
}
