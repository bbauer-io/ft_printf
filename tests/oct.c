/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/02 10:28:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <locale.h>

int		main(void)
{
	ft_printf("93:%%.o %%.0o, 0, 0\n");
	ft_printf(": %.o %.0o:", 0, 0);
	ft_printf("\n:  :expected\n\n");

	ft_printf("94: %%5.o %%5.0o, 0, 0\n");
	ft_printf(": %5.o %5.0o:", 0, 0);
	ft_printf("\n:            :expected\n\n");

	ft_printf("95:%%#.o %%#.0o, 0, 0\n");
	ft_printf(": %#.o %#.0o:", 0, 0);
	ft_printf("\n: 0 0:expected");
	return (0);
}
