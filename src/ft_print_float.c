/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:10:46 by tcase             #+#    #+#             */
/*   Updated: 2019/05/13 16:14:53 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_printf_ftoa(intmax_t num)
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

static int		ft_print_ftoa_prec(char *right, t_pf *pf)
{
	if1f	
}

static int		ft_print_ftoa(long int left, long int right, t_pf *pf)
{
	int		llen;
	int		rlen;
	char	*str;
	char	*tmp;

	llen = ft_nbrlen(left, 10);
	rlen = ft_nbrlen(right, 10);
	if (!(str = ft_strnew(llen + rlen + 2)))
		ft_printf_cleanup(pf);
	if (!(tmp = ft_printf_ftoa(left)))
		ft_printf_cleanup(pf);
	ft_memcpy(str, tmp, llen);
	free(tmp);
	str[llen] = '.';
	if (!(tmp = ft_printf_ftoa(right)))
		ft_printf_cleanup(pf);
	if (!(ft_print_ftoa_prec(right, pf)))
		ft_printf_cleanup(pf);
	ft_memcpy(&str[llen + 1], tmp, rlen);
	free(tmp);
	ft_putstr(str);
	return (llen + rlen + 1);
}

int				ft_print_float(double dbl, t_pf *pf)
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
	return (ft_print_ftoa(left, right, pf));
}
