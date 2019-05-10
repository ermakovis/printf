/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:45:55 by tcase             #+#    #+#             */
/*   Updated: 2019/05/10 17:47:42 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int				ft_wstrlen(wchar_t *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len += ft_wchrlen(*str);
		str++;
	}
	return (len);
}

int				ft_wchrlen(wchar_t wch)
{
	int len;

	len = 0;
	if (wch <= 0x7F)
		len = 1;
	else if (wch <= 0x7FF)
		len = 2;
	else if (wch <= 0xFFFF)
		len = 3;
	else if (wch <= 0x10FFFF)
		len = 4;
	return (len);
}

static int		ft_convert_wchar(wchar_t wch, char *new)
{
	int		len;

	len = 0;
	if (wch <= 0x7F)
		new[len++] = wch;
	else if (wch <= 0x7FF)
	{
		new[len++] = ((wch >> 6) | 0xC0);
		new[len++] = (((wch >> 0) & 0x3F) | 0x80);
	}
	else if (wch <= 0xFFFF)
	{
		new[len++] = ((wch >> 12) | 0xE0);
		new[len++] = (((wch >> 6) & 0x3F) | 0x80);
		new[len++] = ((wch & 0x3F) | 0x80);
	}
	else if (wch <= 0x10FFFF)
	{
		new[len++] = ((wch >> 18) | 0xF0);
		new[len++] = (((wch >> 12) & 0x3F) | 0x80);
		new[len++] = (((wch >> 6) & 0x3F) | 0x80);
		new[len++] = ((wch & 0x3F) | 0x80);
	}
	return (len);
}

void			ft_putwstr(wchar_t *wstr)
{
	wchar_t *tmp;

	tmp = wstr;
	while (*tmp)
	{
		ft_putwchar(*tmp);
		tmp++;
	}
}

void			ft_putwchar(wchar_t wch)
{
	int		len;
	char	new[4];

	len = ft_convert_wchar(wch, new);
	write(1, new, len);
}
