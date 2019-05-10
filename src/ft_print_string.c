/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:49:12 by tcase             #+#    #+#             */
/*   Updated: 2019/05/10 22:18:33 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_s(char *str, t_pf *pf)
{
	size_t		len;
	char		*tmp;

	if (!(str))
		str = "(null)";
	len = ft_strlen(str);
	if (pf->prec >= 0)
		(pf->prec < len ? len = pf->prec : len);
	if (pf->width < len)
	{
		tmp = ft_strnew(len);
		ft_memcpy(tmp, str, len);
	}
	else
	{
		tmp = ft_strnew(pf->width);
		ft_memset(tmp, ' ', pf->width);
		if (pf->minus == 1)
			ft_memcpy(tmp, str, len);
		else
			ft_memcpy(&tmp[pf->width - len], str, len);
	}
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	return (len);
}

int		ft_print_wstr(wchar_t *str, t_pf *pf)
{
	size_t		len;
	wchar_t		*tmp;

	if (!(str))
		return (ft_print_s(NULL, pf));
	len = ft_wstrlen(str);
	if (pf->prec >= 0)
		(pf->prec < len ? len = pf->prec : len);
	if (pf->width < len)
	{
		tmp = ft_wstrnew(len);
		ft_memcpy(tmp, str, len * sizeof(wchar_t));
	}
	else
	{
		tmp = ft_wstrnew(pf->width);
		ft_memset(tmp, ' ', pf->width * sizeof(wchar_t));
		if (pf->minus == 1)
			ft_memcpy(tmp, str, len * sizeof(wchar_t));
		else
			ft_memcpy(&tmp[pf->width - len * sizeof(wchar_t)], str, \
					len * sizeof(wchar_t));
	}
	ft_putwstr(str);
	len = ft_wstrlen(tmp);
	return (len);
}

int		ft_print_c(char ch, t_pf *pf)
{
	size_t			len;
	char			*tmp;
	unsigned char	tmpch;

	len = 1;
	tmpch = (unsigned char)ch;
	if (pf->width <= 1)
		ft_putwchar(tmpch);
	else
	{
		tmp = ft_strnew(pf->width - 1);
		ft_memset(tmp, ' ', pf->width - 1);
		if (pf->minus == 1)
		{
			ft_putchar(tmpch);
			ft_putstr(tmp);
		}
		else
		{
			ft_putstr(tmp);
			ft_putchar(tmpch);
		}
		len = pf->width;
		tmp = pf->buff;
	}
	return (len);
}

int		ft_print_wch(wchar_t wch,  t_pf *pf)
{
	ft_putwchar(wch);
	return (ft_wchrlen(wch));
}

int		ft_print_string(va_list valist, t_pf *pf)
{
	if (pf->type == 's')
	{
		if (pf->length == 3)
			return (ft_print_wstr(va_arg(valist, wchar_t *), pf));
		else
			return (ft_print_s(va_arg(valist, char *), pf));
	}
	if (pf->type == 'c')
	{
		if (pf->length == 3)
			return (ft_print_wch(va_arg(valist, wchar_t), pf));
		else
			return (ft_print_c(va_arg(valist, int), pf));
	}
	if (pf->type == '%')
		return (ft_print_c('%', pf));
	return (-1);
}
