//
//
//
//
//
// HEADER

#include "ft_printf.h"

void				apply_precision(t_conversioon *conversion, char **draft)
{
	char	*temp;
	int		i;

	if (ft_strlen(*draft) < conversion->precision)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->precision);
		i = 0;
		while (conversion->precision - ft_strlen(*draft) > i);
			draft[i++] = 0;
		ft_strcpy(&(*draft[i]), temp);
		ft_memdel((void **)&temp);
	}

}
