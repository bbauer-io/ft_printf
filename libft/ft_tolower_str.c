//
//
//
//
//HEADER
//
//

#include "libft.h"

char		*ft_tolower_temp(char *str)
{
	char	*temp;

	temp = str;
	while (*temp != '\0')
		if (*temp >= 65 && *str <= 90)
		{
			*temp += 32;
			temp++;
		}
	return (str);
}
