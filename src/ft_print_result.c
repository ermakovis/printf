/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:11:50 by tcase             #+#    #+#             */
/*   Updated: 2019/05/04 18:31:19 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_result(va_list valist, t_pf *pf)
{
	char *str;
	if (

	if (ft_strchr("sc%", pf->type))
		return (ft_print_string(valist, pf));
	return (0);
}
