/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:43:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/29 15:20:47 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

# define ERROR		1
# define GOOD		0

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef struct		s_flags
{
	t_bool		hash;
	t_bool		left_justify;
	t_bool		pad_with_zeros;
	t_bool		pos_values_begin_w_space;
	t_bool		show_sign;
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

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	INVALID_SPECIFIER
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			precision_set;
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
** flag is encountered, all of these functions will be called to process The
** specifiers.
*/

int					read_flags(t_conversion *conversion, t_format *format);
int					read_width(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_precision(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_length(t_conversion *conversion, t_format *format);
int					read_specifier(t_conversion *conversion, t_format *format);
int					verify_flag_compatibility(t_conversion *conversion,
											t_format *format);
int					verify_flag_compatibility_continued(t_conversion
											*conversion, t_format *format);

/*
** The following functions will print the stored data in the format specified
** by the stored flags.
*/

void				write_conversion_substr(t_conversion *conversion,
											va_list ap, t_format *format);
void				write_signed_int(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_unsigned_int(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_hex(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_octal(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_string(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_char(t_conversion *conversion, va_list ap,
											t_format *format);

#endif
