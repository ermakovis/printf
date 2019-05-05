/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:11:50 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 19:25:19 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_result(va_list valist, t_pf *pf)
{
	if (ft_strchr("di", pf->type))
		return (ft_printf_signed_number(valist, pf));
	if (ft_strchr("pouxX", pf->type))
		return (ft_printf_unsigned_number(valist, pf));
	if (ft_strchr("sc%", pf->type))
		return (ft_print_string(valist, pf));
	return (0);
}