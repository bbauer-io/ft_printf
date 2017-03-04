/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 11:30:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{

	setlocale(LC_ALL, "");
	ft_printf("WCHARS:\n");

	ft_printf("%lc", L'猫');
	ft_printf("\n");
	ft_printf("%lc", L'δ');
	ft_printf("\n");
	ft_printf("%lc", L'요');
	ft_printf("\n");
	ft_printf("%lc", L'莨');
	ft_printf("\n");
	ft_printf("%lc", L'ي');
	ft_printf("\n");
	ft_printf("%lc", 0);
	printf("\n%lc", 0);
	ft_printf("\n");


	ft_printf("\nWSTRINGS:\n");
	ft_printf("%S", L"米");
	ft_printf("\n");
	ft_printf("%S", L"Á±≥");
	ft_printf("\n");
	ft_printf("%S", L"我是一只猫。");
	ft_printf("\n");
	ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
	ft_printf("\n");
	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
			L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
			L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	ft_printf("\n");


return (0);
}
