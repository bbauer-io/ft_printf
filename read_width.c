// Add 42 Header
//
//
//
//
//f
//
//
//
//

#include "ft_printf.h"

/*
** A special/simplified atoi that works well in the read-width function where
** are only reading one character at a time.
*/

static void	ft_atoi_incrementer(const char c, unsigned int *nbr)
{
	if (*nbr)
		*nbr *= 10;
	*nbr += c - '0';
}

/*
** Read specified width, get va_arg if the width is a * (specified in arguments
** instead of in the format string).
*/

int			read_width(t_conversion *conversion, va_list ap, t_format *format)
{
	size_t		counter;

	if (format->str[format->index] == '*')
	{
		conversion->width = va_arg(ap, unsigned int);
		format->index++;
	}
	else
	{
		counter = 0;
		while (ft_isdigit(format->str[format->index]))
		{
			ft_atoi_incrementer(format->str[format->index], &conversion->width);
			counter++;
		}
		format->index += counter;
	}
	return (GOOD);
}
