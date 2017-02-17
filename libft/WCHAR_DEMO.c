/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:11:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 17:00:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "libft.h"

int		main(void)
{
	wchar_t		derp = L'Ξ';

	wchar_t		*str = L"我是一只猫。";
	
	
	char		*a;
	int			i;
	char		*b;

	a = (char *)malloc(sizeof(char) * 6);
	a[0] = 0xCE;
	a[1] = 0x9E;
	a[2] = 0xCE;
	a[3] = 0x9E;
	a[4] = 0xCE;
	a[5] = 0x9E;

	derp = ft_utf8charencode(derp);
	i = 0;
	while (i < 6)
		i += ft_wctomb(&a[i], derp);
	setlocale(LC_ALL, "en_US.UTF-8");

	b = ft_utf8strencode(str);
	write(1, a, 6);
	printf("printf (not mine):\t%C\n", L'Ξ');
	write(1, b, 18);
	ft_putchar('\n');
	ft_putstr(b);
}
/*
int             main(void)
{
	char	a[6];

	a[0] = 0xCE;
	a[1] = 0x9E;
	a[2] = 0xCE;
	a[3] = 0x9E;
	a[4] = 0xCE;
	a[5] = 0x9E;

	setlocale(LC_ALL, "en_US.UTF-8");
	write(1, &a, 6);
	printf("printf (not mine):\t%C\n", L'Ξ');
}*/
