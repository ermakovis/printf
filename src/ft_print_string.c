/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:49:12 by tcase             #+#    #+#             */
/*   Updated: 2019/05/18 22:19:46 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_s(char *str, t_pf *pf, t_res *res)
{
	size_t		len;

	if (!(str))
		str = "(null)";
	len = ft_strlen(str);
	if (pf->prec >= 0)
		(pf->prec < len ? len = pf->prec : len);
	if (pf->width < len)
		pf->buff = ft_strdup(str);
	else
	{
		pf->buff = ft_strnew(pf->width);
		(pf->zero) ? ft_memset(pf->buff, '0', pf->width) :\
			ft_memset(pf->buff, ' ', pf->width);
		if (pf->minus == 1)
			ft_memcpy(pf->buff, str, len);
		else
			ft_memcpy(&pf->buff[pf->width - len], str, len);
		len = ft_strlen(pf->buff);
	}
	ft_printf_buffer(pf, res, pf->buff, len);
	if (*pf->buff)
		free(pf->buff);
}

void	ft_printf_wstr(wchar_t *str, t_pf *pf, t_res *res)
{
	char	*chstr;

	if (!(str))
	{
		ft_printf_s(NULL, pf, res);
		return ;
	}
	chstr = ft_convert_wstr(str, pf);
	ft_printf_s(chstr, pf, res);
	if (*chstr)
		free(chstr);
}

void	ft_printf_c(unsigned char ch, t_pf *pf, t_res *res)
{
	if (pf->width <= 1)
		ft_printf_buffer(pf, res, &ch, 1);
	else
	{
		pf->buff = ft_strnew(pf->width);
		(pf->zero) ? ft_memset(pf->buff, '0', pf->width) :\
			ft_memset(pf->buff, ' ', pf->width);
		if (pf->minus == 1)
			ft_memcpy(pf->buff, &ch, 1);
		else
			ft_memcpy(&pf->buff[pf->width - 1], &ch, 1);
		ft_printf_buffer(pf, res, pf->buff, pf->width);
	}

}

void	ft_printf_wch(wchar_t wch, t_pf *pf, t_res *res)
{
	char	*str;

	if (wch == '\0')
		ft_printf_c('\0', pf, res);
	else
	{
		str = ft_convert_wchar(wch, 0);
		ft_printf_s(str, pf, res);
		free(str);
	}
}

void	ft_printf_string(va_list valist, t_pf *pf, t_res *res)
{
	if (pf->type == 's')
	{
		if (pf->length == 3)
			ft_printf_wstr(va_arg(valist, wchar_t *), pf, res);
		else
			ft_printf_s(va_arg(valist, char *), pf, res);
	}
	else if (pf->type == 'c')
	{
		if (pf->length == 3)
			ft_printf_wch(va_arg(valist, wchar_t), pf, res);
		else
			ft_printf_c(va_arg(valist, int), pf, res);
	}
	if (pf->type == '%')
		ft_printf_c('%', pf, res);
}
