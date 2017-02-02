///
//
//
//
//
// HEADER
//

#include "ft_printf.h"

void				write_char(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char		c;
	wchar_t		d;

	if (conversion->flags.hash)
		return ;
	if (conversion->length == L)
	{
		d = va_arg(ap, wint_t);
		ft_putchar(d);
		format->chars_written++;
	}
	else
	{
		c = va_arg(ap, int);
		ft_putchar(c);
		format->chars_written++;
	}
}
