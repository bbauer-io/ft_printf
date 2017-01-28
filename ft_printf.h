/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:43:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/27 20:08:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

# define ERROR		1
# define GOOD		0

//typedef int			t_bool;

typedef struct		s_flags
{
	int			hash;
	int			left_justify;
	int			pad_with_zeros;
	int			pos_values_begin_w_space;
	int			show_sign;
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

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	int				precision_set;
	t_length		length;
	t_specifier		specifier;
}					t_conversion;

/*
** These are the main functions that might be used within a larger program.
*/

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list arg);

/*
** Functions for reading the various flags of each conversion. (Each time a '%'
** flag is encountered, all of these functions will be executed in the order
** listed here to process the specifiers.
*/

int					read_conversion_substr(t_conversion *conversion,
											va_list ap, t_format *format);
int					read_flags(t_conversion *conversion, t_format *format);
int					read_width(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_precision(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_length(t_conversion *conversion, t_format *format);
int					read_specifier(t_conversion *conversion, t_format *format);
int					verify_flag_harmony(t_conversion *conversion,
											t_format *format);

/*
** The following functions will print the stored data in the format specified
** by the stored flags.
*/

#endif
