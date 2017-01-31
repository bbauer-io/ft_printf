/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:22:38 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/31 15:35:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int main()
{
	printf("Strings:\n");
	const char* s = "Hello";
	ft_printf("\t[%10s]\n\t[%-10s]\n\t[%*s]\n\t[%-10.*s]\n\t[%-*.*s]\n", s, s, 10, s, 4, s, 10, 4, s);
	ft_printf("Characters:\t%c %%\n", 65);
	ft_printf("Integers\n");
	ft_printf("Decimal:\t%i %d %.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	ft_printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
	ft_printf("Octal:\t%o %#o %#o\n", 10, 10, 4);
	ft_printf("Floating point\n");
	ft_printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.5);
	ft_printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
	ft_printf("Scientific:\t%E %e\n", 1.5, 1.5);
	ft_printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);
	ft_printf("Special values:\t0/0=%g 1/0=%g\n", 0.0/0.0, 1.0/0.0);
	ft_printf("Variable width control:\n");
	ft_printf("right-justified variable width: '%*c'\n", 5, 'x');
	int r = ft_printf("left-justified variable width : '%*c'\n", -5, 'x');
	ft_printf("(the last printf printed %d characters)\n", r);
	return (0);
}
