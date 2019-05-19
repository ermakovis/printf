/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:10:46 by tcase             #+#    #+#             */
/*   Updated: 2019/05/18 22:16:38 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_printf_ftoa(intmax_t num)
{
	int		size;
	char	*buff;

	if (num < -9223372036854775807)
	{
		buff = ft_strdup("-9223372036854775808");
		return (buff);
	}
	size = ft_nbrlen(num, 10);
	if (num < 0)
		num = -num;
	buff = ft_strnew(size);
	buff[0] = '-';
	if (num == 0)
		buff = ft_strdup("0");
	while (num > 0)
	{
		buff[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (buff);
}

static void		ft_printf_comb_float(long int left, long int right, t_pf *pf, t_res *res)
{
	int		llen;
	int		rlen;
	char	*tmp;

	llen = ft_nbrlen(left, 10);
	rlen = ft_nbrlen(right, 10);
	if (!(pf->buff = ft_strnew(llen + rlen + 2)))
		ft_printf_cleanup(pf);
	if (!(tmp = ft_printf_ftoa(left)))
		ft_printf_cleanup(pf);
	ft_memcpy(pf->buff, tmp, llen);
	free(tmp);
	(pf->buff)[llen] = '.';
	if (!(tmp = ft_printf_ftoa(right)))
		ft_printf_cleanup(pf);
	ft_memcpy(&(pf->buff)[llen + 1], tmp, rlen);
	free(tmp);
}

static void		ft_printf_w(char *str, t_pf *pf, t_res *res)
{
	size_t		len;

	if (!(str))
		str = "(null)";
	len = ft_strlen(str);
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

void				ft_printf_float(double dbl, t_pf *pf, t_res *res)
{
	double		decimal;
	long int	right;
	long int	left;
	char		*result;

	if (pf->prec == -1)
		pf->prec = 6;
	left = (long long int)dbl;
	decimal = (dbl > 0 ? dbl : -dbl);
	decimal = (decimal - (long long int)(decimal)) * ft_power(10, pf->prec + 1);
	decimal = ((long long int)decimal % 10 > 4) ?\
		decimal / 10 + 1 : decimal / 10;
	right = (long long int)decimal;
	ft_printf_comb_float(left, right, pf, res);
	ft_printf_w(pf->buff, pf, res);
}
