/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:43:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/22 18:08:58 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

# define ERROR		1
# define OKAY		0

typedef int			t_bool;

typedef struct		s_flags
{
	t_bool			hashtag;
	t_bool			left_justify;
	t_bool			pad_with_zeroes;
	t_bool			positive_values_begin_blank;
	t_bool			show_sign;
}					t_flags;

typedef struct		s_format
{
	const char		*str;
	size_t			index;
	size_t			chars_written;
}					t_format;

typedef enum		e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}					t_length;

typedef enum			e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	INVALID_SPECIFIER
}						t_specifier;

typedef struct		s_arguments
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			precision_set;
	t_length		length;
	t_specifier		specifier;
}					t_arguments;

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list arg);

#endif
