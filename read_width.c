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
** Read specified width, get va_arg if the width is a * (specified in arguments
** instead of in the format string).
*/

/*
** I am wondering if I need a new atoi that returns an Unsigned int here...
*/

int			read_width(t_conversion *conversion, va_list ap, t_format *format)
{
	size_t		counter;
	char		*ascii_nbr;

	if (format->str[format->index] == '*')
	{
		conversion->width = va_arg(ap, unsigned int);
		format->index++;
	}
	else
	{
		counter = 0;
		while (ft_isdigit(format->str[format->index]))
			counter++;
		if (counter > 0)
		{
			format->index += counter;
			ascii_nbr = ft_strndup(&format->str[format->index], counter);
			conversion->width = ft_atoi(ascii_nbr);
			ft_memdel((void **)&ascii_nbr);
		}
	}
	return (GOOD);
}
