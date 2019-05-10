/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:13:32 by tcase             #+#    #+#             */
/*   Updated: 2019/05/10 20:55:21 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_basebyletter(t_pf *pf)
{
	if (pf->type == 'u')
		return (10);
	if (pf->type == 'x' || pf->type == 'X' || pf->type == 'p')
		return (16);
	if (pf->type == 'o')
		return (8);
	return (0);
}

int		ft_printf_uitoa(uintmax_t num, t_pf *pf)
{
	int		size;
	char	*tab;
	int		base;

	tab = "0123456789abcdef";
	base = ft_printf_basebyletter(pf);
	size = 0;
	if (base < 2 || base > 16)
		return (0);
	size = ft_unbrlen(num, base);
	pf->buff = ft_strnew(size);
	while (size-- > 0)
	{
		pf->buff[size] = tab[num % base];
		num /= base;
	}
	return (ft_printf_digit(pf));
}

int		ft_printf_unsigned_number(va_list valist, t_pf *pf)
{
	if (pf->length == 1)
		return (ft_printf_uitoa(va_arg(valist, unsigned long long int), pf));
	if (pf->length == 2)
		return (ft_printf_uitoa((unsigned char)va_arg(valist, int), pf));
	if (pf->length == 3)
		return (ft_printf_uitoa(va_arg(valist, unsigned long int), pf));
	if (pf->length == 4)
		return (ft_printf_uitoa((unsigned short)va_arg(valist, int), pf));
	if (pf->length == 5)
		return (ft_printf_uitoa(va_arg(valist, uintmax_t), pf));
	if (pf->length == 6)
		return (ft_printf_uitoa(va_arg(valist, size_t), pf));
	return (ft_printf_uitoa(va_arg(valist, unsigned int), pf));
}
