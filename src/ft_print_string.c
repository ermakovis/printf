/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:49:12 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 20:39:54 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_s(va_list valist, t_pf *pf)
{
	size_t		len;
	char		*tmp;
	char		*str;

	if (!(str = va_arg(valist, char *)))
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

int		ft_print_c(char ch, t_pf *pf)
{
	size_t			len;
	char			*tmp;
	unsigned char	tmpch;

	len = 1;
	tmpch = (unsigned char)ch;
	if (pf->width <= 1)
		ft_putchar(tmpch);
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

int		ft_print_string(va_list valist, t_pf *pf)
{
	if (ft_strchr("s", pf->type))
		return (ft_print_s(valist, pf));
	if (ft_strchr("c", pf->type))
		return (ft_print_c(va_arg(valist, int), pf));
	if (ft_strchr("%", pf->type))
		return (ft_print_c('%', pf));
	return (-1);
}
