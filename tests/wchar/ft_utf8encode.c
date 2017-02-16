/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:11:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/15 18:50:38 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
typedef char	t_utf8;

char	*ft_itoa_base_uintmax(uintmax_t value, int base);

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned int		i;
	unsigned int		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
** Count number of bits needed to represent a unicode code point.
*/

size_t			ft_wchrbits(wchar_t c)
{
	size_t		i;

	i = 0;
	while (c > 0)
	{
		c = c >> 1;
		i++;
	}
	return (i);
}

/*
** Returns the number of bytes that will be needed to represent a unicode code
** point in UTF-8 format.
*/

size_t			ft_wchrsize_utf8(wchar_t c)
{
	size_t		bits;

	bits = ft_wchrbits(c);
	if (bits <= 7)
		return (1);
	if (bits <= 11)
		return (2);
	if (bits <= 16)
		return (3);
	if (bits <= 21)
		return (4);
	else
		return (0);
}

/*
** Returns the number of bytes needed to represent a string of unicode code
** points after it has been encoded to UTF-8.
*/

size_t			ft_wstrsize_utf8(const wchar_t *wstr)
{
	size_t		size;

	if (!wstr)
		return (0);
	size = 0;
	while (*wstr != '\0')
	{
		size += ft_wchrsize_utf8(*wstr);
		wstr++;
	}
	return (size);
}

/*
** Encodes a wchar_t to UTF-8 or returns the "substitute" character.
*/

wchar_t			ft_utf8chrencode(wchar_t c)
{
	size_t		size;

	size = ft_wchrbits(c);
	if (size <= 7)
		return (c);
	if (size <= 11)
		return (((c >> 6) << 8) | ((c << 26) >> 26) | 0xC080);
	if (size <= 16)
		return (((c >> 12) << 14) | (((c >> 6) << 26) >> 18)
			| ((c << 26) >> 26) | 0xE08080);
	if (size <= 21)
		return (((c >> 18) << 24) | (((c >> 12) << 26) >> 10)
			| (((c >> 6) << 26) >> 18) | ((c << 26) >> 26) | 0xF0808080);
	return (0x1A);
}

/*
** Encodes a string of wchar unicode code points in utf8.
*/

t_utf8			*ft_utf8encode(const wchar_t *wstr)
{
	size_t		i;
	size_t		size;
	size_t		len;
	wchar_t		c;
	t_utf8		*utf8;

	len = ft_wstrsize_utf8(wstr);
	if (len > 0)
		if ((utf8 = (t_utf8 *)malloc(sizeof(t_utf8) * (len + 1))))
		{
			i = 0;
			while (i < len)
			{
				c = ft_utf8chrencode(*wstr);
				size = ft_wchrsize_utf8(c);
				ft_memcpy(&utf8[i], &c, size);
				i += size;
				wstr++;
			}
			utf8[i] = '\0';
			return (utf8);
		}
	return (NULL);
}

/*
void			ft_putwstr_utf8(t_utf8 *s)
{
	
}
*/
size_t		ft_utf8chrsize(wchar_t c)
{
	unsigned int	f;

	f = c;
	if (f < 0xFF)
		return (1);
	if (f < 0xFFFF)
		return (2);
	if (f < 0xFFFFFF)
		return (3);
	if (f < 0xFFFFFFFF)
		return (4);
	return (0);
}

void			ft_putwchr(wchar_t c)
{
	c = ft_utf8chrencode(c);
	
	write(1, &c, sizeof(wchar_t));

	//	write(1, &c, ft_utf8chrsize(c));
}

void			ft_putwstr(wchar_t *s)
{
	while (*s != '\n')
		ft_putwchr(*s++);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	 while (*s)
		 ft_putchar(*s++);
}

int		main(void)
{
	wchar_t		derp = L'Ξ';
	wchar_t		doublederp;
	wchar_t		reversederp;
	char		a[6];

	a[0] = 0xCE;
	a[1] = 0x9E;
	a[2] = 0xCE;
	a[3] = 0x9E;
	a[4] = 0xCE;
	a[5] = 0x9E;

	doublederp = ft_utf8chrencode(derp);
	doublederp = doublederp | (doublederp << 16);
	reversederp = ft_utf8chrencode(derp);
	reversederp = (reversederp >> 8) | ((reversederp << 24) >> 16);

	ft_putchar(MB_CUR_MAX + '0');
	setlocale(LC_ALL, "en_US.UTF-8");
	ft_putchar(MB_CUR_MAX + '0');
	ft_putstr("Locale is set:\t\t");
	ft_putstr(setlocale(LC_ALL, NULL));
	ft_putstr("\nUnicode code point:\t");
	ft_putstr(ft_itoa_base_uintmax(derp, 16));
	ft_putstr("\nConverted UTF-8 binary:\t");
	ft_putstr(ft_itoa_base_uintmax(ft_utf8chrencode(derp), 2));
	ft_putstr("\nAnd HEX:\t\t");
	ft_putstr(ft_itoa_base_uintmax(ft_utf8chrencode(derp), 16));
	ft_putstr("\nResult of writing:\t");
	write(1, &doublederp, 4);
	ft_putstr("\n");
	ft_putstr(ft_itoa_base_uintmax(doublederp, 2));
	ft_putstr("\n");
	write(1, &reversederp, 4);
	ft_putstr("\n");
	ft_putstr(ft_itoa_base_uintmax(reversederp, 2));
	ft_putchar('\n');
	write(1, &a, 6);
	printf("printf (not mine):\t%C\n", L'Ξ');
}
