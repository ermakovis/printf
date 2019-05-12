/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:49:12 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 20:22:53 by tcase            ###   ########.fr       */
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
		tmp = ft_strdup(str);
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
	write(1, tmp, len);
	if (*tmp)
		free(tmp);
	return (len);
}

int		ft_print_wstr(wchar_t *str, t_pf *pf)
{
	int		i;
	char	*chstr;

	if (!(str))
		return (ft_print_s(NULL, pf));
	chstr = ft_convert_wstr(str, pf);
	i = ft_print_s(chstr, pf);
	if (*chstr)
		free(chstr);
	return (i);
}

int		ft_print_c(unsigned char ch, t_pf *pf)
{
	size_t			len;
	char			*tmp;

	len = 1;
	if (pf->width <= 1)
		ft_putchar(ch);
	else
	{
		tmp = ft_strnew(pf->width);
		(pf->zero) ? ft_memset(tmp, '0', pf->width) :\
			ft_memset(tmp, ' ', pf->width);
		if (pf->minus == 1)
			ft_memcpy(tmp, &ch, 1);
		else
			ft_memcpy(&tmp[pf->width - 1], &ch, 1);
		write(1, tmp, pf->width);
		len = pf->width;
	}
	return (len);
}

int		ft_print_wch(wchar_t wch, t_pf *pf)
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
