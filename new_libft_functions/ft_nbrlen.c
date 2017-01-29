/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:24:38 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/29 15:29:32 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of digits stored in a number. Useful for preparing an
** array of chars to hold a number, particulary when other formatting may be
** involved (I created this functionfor for use within ft_printf).
*/

size_t			ft_nbrlen(int nbr)
{
	size_t		len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
