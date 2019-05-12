/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:49:12 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 17:08:28 by tcase            ###   ########.fr       */
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
		(pf->zero) ? ft_memset(tmp, '0', pf->width) :\
			ft_memset(tmp, ' ', pf->width);
		if (pf->minus == 1)
			ft_memcpy(tmp, str, len);
		else
			ft_memcpy(&tmp[pf->width - len], str, len);
		len = ft_strlen(tmp);
	}
	ft_putstr(tmp);
	return (len);
}

int		ft_print_wstr(wchar_t *str, t_pf *pf)
{
	if (!(str))
		return(ft_print_s(NULL, pf));
	return(ft_print_s(ft_convert_wstr(str, pf), pf));
}

int		ft_print_c(unsigned char ch, t_pf *pf)
{
	size_t			len;
	char			*tmp;
	unsigned char	tmpch;

	len = 1;
	if (pf->width <= 1)
		ft_putchar(ch);
	else
	{
		tmp = ft_strnew(pf->width - 1);
		(pf->zero) ? ft_memset(tmp, '0', pf->width -1) :\
			ft_memset(tmp, ' ', pf->width - 1);
		if (pf->minus == 1)
		{
			ft_putchar(ch);
			ft_putstr(tmp);
		}
		else
		{
			ft_putstr(tmp);
			ft_putchar(ch);
		}
		len = pf->width;
		tmp = pf->buff;
	}
	return (len);
}

int		ft_print_wch(wchar_t wch,  t_pf *pf)
{
	if (wch == '\0')
		return (ft_print_c('\0', pf));
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
