/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:39:45 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 20:46:13 by tcase            ###   ########.fr       */
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

int								ft_print_c(unsigned char ch, t_pf *pf);
int								ft_print_s(char *str, t_pf *pf);
int								ft_wchrlen(wchar_t wch);
int								ft_wstrlen(wchar_t *wstr);
char							*ft_convert_wchar(wchar_t wch, int len);
char							*ft_convert_wstr(wchar_t *wstr, t_pf *pf);
void							ft_putwchar(wchar_t wch);
int								ft_printf_uitoa(uintmax_t num, t_pf *pf);
int								ft_print_string(va_list valist, t_pf *pf);
int								ft_printf_digit(t_pf *pf);
int								ft_parse_format(char **line, t_pf *pf,\
									va_list valist);
int								ft_printf(const char *format, ...);
int								ft_print_float(double dbl, t_pf *pf);
int								ft_printf_unsigned_number(va_list valist,\
									t_pf *pf);
int								ft_printf_signed_number(va_list valist, \
									t_pf *pf);
void							ft_printf_cleanup(t_pf *pf);

#endif
