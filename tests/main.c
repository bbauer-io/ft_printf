/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/17 17:41:46 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int		main(void)
{
	char	*nullstr;
	char	*goodstr = "goodstr";

	nullstr = NULL;
	ft_printf("holy crapola!\n");
	ft_printf("holy crapola %d: shitbats!\n", 2);
	ft_printf("holy crapola %d: %dxtriple shitbats!\n", 3, 3);
	ft_printf("double percentage test %%");
	ft_printf("\nnull string: %s\n", nullstr);
	ft_printf("{%s}", 0);
	ft_printf("\nnull pointer: %p", nullstr);
	ft_printf("\nvalid pointer: %p", goodstr);
	ft_printf("\nsharp null char #: %#c~", 0);



return (0);
}
