/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:18:46 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 19:58:55 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "../includes/ft_printf.h"

int		ft_printf_itoa(intmax_t num, t_pf *pf)
{
	int		size;

	if (num < -9223372036854775807)
	{
		pf->buff = ft_strdup("-9223372036854775808");
		return ft_printf_digit(pf);
	}
	size = ft_nbrlen(num, 10);
	if (num < 0)
		num = -num;
	pf->buff = ft_strnew(size);
	pf->buff[0] = '-';
	if (num == 0)
		pf->buff = ft_strdup("0");
	while (num > 0)
	{
		pf->buff[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (ft_printf_digit(pf));
}

int		ft_printf_signed_number(va_list valist, t_pf *pf)
{
	if (pf->length == 1)
		return (ft_printf_itoa(va_arg(valist, long long int), pf));
	if (pf->length == 2)
		return (ft_printf_itoa((char)va_arg(valist, int), pf));
	if (pf->length == 3)
		return (ft_printf_itoa(va_arg(valist, long int), pf));
	if (pf->length == 4)
		return (ft_printf_itoa((short int)va_arg(valist,  int), pf));
	if (pf->length == 5)
		return (ft_printf_itoa(va_arg(valist, intmax_t), pf));
	if (pf->length == 6)
		return (ft_printf_itoa(va_arg(valist, size_t), pf));
	return (ft_printf_itoa(va_arg(valist, int), pf));
}