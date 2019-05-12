/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:03:20 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 11:58:31 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_pf		*init_pf(void)
{
	t_pf *new;

	if (!(new = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	new->form = NULL;
	new->len = 0;
	new->hash = 0;
	new->zero = 0;
	new->plus = 0;
	new->minus = 0;
	new->space = 0;
	new->width = 0;
	new->prec = -1;
	new->length = 0;
	new->type = 0;
	return (new);
}

int			ft_printf(const char *format, ...)
{
	va_list valist;
	t_pf	*pf;
	int		i;
	char	*line;
	char	*s;

	i = 0;
	line = (char *)format;
	va_start(valist, format);
	while (*line)
	{
		if (*line == '%')
		{
			if (!(pf = init_pf()))
				return (-1);
			line++;
			if (ft_parse_format(&line, pf, valist))
				i += ft_print_result(valist, pf);
			else
				return (0);
			free(pf);
		}
		else
		{
			ft_putchar(*line);
			line++;
			i++;
		}
	}
	va_end(valist);
	return (i);
}
