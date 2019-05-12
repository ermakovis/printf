/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:03:20 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 20:43:34 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_pf		*init_pf(void)
{
	t_pf *new;

	if (!(new = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	new->buff = NULL;
	new->len = 0;
	new->hash = 0;
	new->zero = 0;
	new->plus = 0;
	new->minus = 0;
	new->space = 0;
	new->width = 0;
	new->prec = -1;
	new->length = 0;
	new->type = '0';
	return (new);
}

static int		ft_print_result(va_list valist, t_pf *pf)
{
	if (ft_strchr("di", pf->type))
		return (ft_printf_signed_number(valist, pf));
	else if (ft_strchr("pouxX", pf->type))
		return (ft_printf_unsigned_number(valist, pf));
	else if (ft_strchr("sc%", pf->type))
		return (ft_print_string(valist, pf));
	else if (ft_strchr("fF", pf->type))
		return (ft_print_float(va_arg(valist, double), pf));
	else
		return (ft_print_c(pf->type, pf));
	return (0);
}

static int		ft_printf_cycle(char *line, va_list valist)
{
	int			i;
	t_pf		*pf;

	i = 0;
	while (*line)
	{
		if (*line == '%')
		{
			if (!(pf = init_pf()))
				return (-1);
			line++;
			if (!*line)
				return (i);
			if (ft_parse_format(&line, pf, valist))
				i += ft_print_result(valist, pf);
			free(pf);
		}
		else
		{
			ft_putchar(*line);
			line++;
			i++;
		}
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		valist;
	int			i;

	va_start(valist, format);
	i = ft_printf_cycle(format, valist);
	va_end(valist);
	return (i);
}
