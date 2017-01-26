//
//
//
//
//NNEEDS A HEAEDER!!!
//

#include "ft_printf.h"


/*
** Does the actual comparison of characters and returns the corresponding enum
*/

static t_specifier		compare_specifiers(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	return (INVALID_SPECIFIER);
}

/*
** This function's purpose is to determine the specifier provided by the user in
** the format string which will tell us how to cast the argument we get from
** va_args as well as how to print it.
*/

int						read_specifier(t_conversion *conversion,
													t_format *format)
{
	char	c;

	if (!format->str[format->index])
		return (reached_end_of_format_str_error(format));
	c = format->str[format->index];
	conversion->specifier = compare_specifiers(format->str[format->index]);
	if (conversion->specifier == INVALID_SPECIFIER)
		return (invalid_specifier_error(format));
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
	{
		if (conversion->length != DEFAULT)
			mixed_length_and_dou(format); // can't mix DOU and length specifier -> forces 'l'
		conversion->length = L;
	}
	format->index++;
	return (GOOD);
}
