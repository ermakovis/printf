/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:13:06 by tcase             #+#    #+#             */
/*   Updated: 2019/05/11 19:59:57 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "limits.h"


int		main(void)
{
	//char str[] = "QWE";
	//int	i;
	
	ft_printf("{%30S}", L"我是一只猫。");
	printf("{%30S}", L"我是一只猫。");
	return (0);	
}
