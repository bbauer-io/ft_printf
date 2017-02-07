//
//
//
//
//HEADER
//
//

#include "libft.h"

char		*ft_tolower_str(char *str)
{
	char	*temp;

	temp = str;
	while (*temp != '\0')
	{
		if (*temp >= 65 && *temp <= 90)
			*temp += 32;
		temp++;
	}
	return (str);
}
