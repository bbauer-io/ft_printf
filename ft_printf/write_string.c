///
//
//
//
//
// HEADER
//

#include "ft_printf.h"

void				write_string(t_conversion *conversion, va_list ap, t_format
																	*format)
{
	char	*draft;

	if (conversion && format)
		draft = va_arg(ap, char *);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
}
