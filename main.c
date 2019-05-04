/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:13:06 by tcase             #+#    #+#             */
/*   Updated: 2019/05/03 17:13:06 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	unsigned char s1[] = "HELLO";
	char s2[] = ",";
	char s3[] = "WORLD";
	char s4[] = "!";
	int i1 = -255;
	unsigned char s5;

	//printf("%d\n", ft_strncmp("xh", "hhX", 2));
	printf("   printf -- %.2s is a string\n", "this");
	ft_printf("ft_printf -- %.2s is a string\n", "this");
//	ft_printf("Наверноdoes it work? %c%c%s%s much wow", s1, s2, s3, s4);
	
	//printf("%c", *s1 );
	return (0);	
}
