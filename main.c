/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:13:06 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 21:27:37 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "limits.h"

int		main(void)
{
	//char str[] = "QWE";
	//int	i;

	printf("   printf -- %p\n", NULL);
	ft_printf("ft_printf -- %p\n", NULL);
	return (0);	
}
