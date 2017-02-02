//
//
//
//
//HEADER
//
//

#include "libft.h"

char		*ft_toupper_str(char *str)
{
	char	*temp;

	temp = str;
	while (*temp != '\0')
	{
		if (*temp >= 97 && *str <= 122)
			*temp -= 32;
		temp++;
	}
	return (str);
}
