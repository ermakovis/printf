/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:39:45 by tcase             #+#    #+#             */
/*   Updated: 2019/05/11 16:53:48 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct					s_pf
{
	char						*buff;
	char						*form;
	int							len;
	int							hash;
	int							zero;
	int							plus;
	int							minus;
	int							space;
	int							width;
	int							prec;
	int							length;
	char						type;
}								t_pf;

int								ft_printf_uitoa(uintmax_t num, t_pf *pf);
int								ft_print_result(va_list valist, t_pf *pf);
int								ft_print_string(va_list valist, t_pf *pf);
int								ft_printf_digit(t_pf *pf);
int								ft_parse_format(char **line, t_pf *pf, va_list valist);
int								ft_printf(const char *format, ...);
int								ft_print_float(double dbl, t_pf *pf);
int								ft_printf_unsigned_number(va_list valist,\
									t_pf *pf);
int								ft_printf_signed_number(va_list valist, \
									t_pf *pf);
void							ft_printf_cleanup(t_pf *pf);

#endif
