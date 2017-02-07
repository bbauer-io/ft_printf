/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:42:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/06 19:11:11 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_prefix_hex(t_conversion *conversion, char **draft)
{
	int		i;
	char	prefix_char;
	char	*temp;

	prefix_char = conversion->flags.show_sign ? '+' : ' ';
	i = 0;
	while (!ft_isdigit((*draft)[i]) && (*draft)[i] != '\0')
		i++;
	if (i > 0)
		(*draft)[--i] = prefix_char;
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



static void		apply_prefix_int(t_conversion *conversion, char **draft)
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

void			apply_prefix(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == S_DECIMAL
						|| conversion->specifier == U_DECIMAL)
		apply_prefix_int(conversion, draft);
	if (conversion->specifier == HEX_UPPER
						|| conversion->specifier == HEX_LOWER)
		apply_prefix_hex(conversion, draft);
}
