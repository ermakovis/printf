/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:08:58 by tcase             #+#    #+#             */
/*   Updated: 2019/05/11 19:48:20 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_dprec(t_pf *pf)
{
	char		*tmp;
	int			len;
	int			flag;

	flag = 0;
	if (!(ft_strcmp(pf->buff, "")))
		return ;
	len = ft_strlen(pf->buff);
	if (pf->buff[0] == '-')
		flag = 1;
	if (len > pf->prec + flag)
		return ;
	tmp = ft_strnew(pf->prec + flag);
	ft_memset(tmp, '0', pf->prec + flag);
	ft_memcpy(&tmp[pf->prec - len + flag], pf->buff, len);
	if (tmp[pf->prec - len + flag] == '-' && tmp[0])
		ft_swap(&tmp[pf->prec - len + flag], &tmp[0]);
	free(pf->buff);
	pf->buff = tmp;
}

void	ft_printf_dflags(t_pf *pf)
{
	char		*tmp;
	int			len;

	len = ft_strlen(pf->buff);
	if (ft_strchr("di", pf->type) == 0 && (pf->plus != 1 || pf->space != 1))
		return ;
	if ((pf->space == 1 || pf->plus == 1) && pf->buff[0] != '-')
	{
		tmp = ft_strnew(len + 1);
		ft_memcpy(&tmp[1], pf->buff, len);
		if (pf->space == 1 && pf->plus == 0)
			tmp[0] = ' ';
		if (pf->plus == 1)
			tmp[0] = '+';
		free(pf->buff);
		pf->buff = tmp;
	}
}

void	ft_printf_udflags(t_pf *pf)
{
	char		*tmp;
	int			len;

	len = ft_strlen(pf->buff);
	if (ft_strchr("poxX", pf->type) != 0 && pf->hash != 1)
		return ;
	if (pf->type == 'o' && pf->buff[0] != '0')
	{
		tmp = ft_strnew(len + 1);
		ft_memset(tmp, '0', 1);
		ft_memcpy(&tmp[1], pf->buff, len);
		free(pf->buff);
		pf->buff = tmp;
	}
	if (((pf->type == 'x' || pf->type == 'X') \
			&& (ft_strcmp(pf->buff, "0")) && (ft_strcmp(pf->buff, "")))\
			|| pf->type == 'p')
	{
		tmp = ft_strnew(len + 2);
		ft_memcpy(tmp, "0x", 2);
		ft_memcpy(&tmp[2], pf->buff, len);
		free(pf->buff);
		pf->buff = tmp;
	}
}

void	ft_printf_dwidth(t_pf *pf)
{
	char		*tmp;
	int			len;

	len = ft_strlen(pf->buff);
	if (pf->width < len)
		return ;
	tmp = ft_strnew(pf->width);
	if (pf->zero == 1 && pf->minus == 0 && pf->prec < 0)
		ft_memset(tmp, '0', pf->width);
	else
		ft_memset(tmp, ' ', pf->width);
	if (pf->minus == 1)
		ft_memcpy(tmp, pf->buff, len);
	else
		ft_memcpy(&tmp[pf->width - len], pf->buff, len);
	if (tmp[pf->width - len + 1] == 'x' && tmp[1] == '0' && tmp[0] == '0')
		ft_swap(&tmp[1], &tmp[pf->width - len + 1]);
	if (tmp[pf->width - len] == ' ' && tmp[0] == '0' && pf->space == 1)
		ft_swap(&tmp[0], &tmp[pf->width - len]);
	if (tmp[pf->width - len] == '+' && tmp[0] == '0' && pf->plus == 1)
		ft_swap(&tmp[0], &tmp[pf->width - len]);
	if (tmp[pf->width - len] == '-' && tmp[0] == '0')
		ft_swap(&tmp[0], &tmp[pf->width - len]);
	free(pf->buff);
	pf->buff = tmp;
}

int		ft_printf_digit(t_pf *pf)
{
	int len;

	if (!(ft_strcmp(pf->buff, "0")) && pf->prec == 0)
	{
		free(pf->buff);
		pf->buff = ft_strdup("");
	}
	ft_printf_dprec(pf);
	ft_printf_dflags(pf);
	ft_printf_udflags(pf);
	ft_printf_dwidth(pf);
	if (pf->type == 'X')
	{
		ft_strtoupper(pf->buff);
	}
	ft_putstr(pf->buff);
	len = ft_strlen(pf->buff);
	return (len);
}
