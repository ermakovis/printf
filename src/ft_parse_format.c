/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:48:30 by tcase             #+#    #+#             */
/*   Updated: 2019/05/13 14:32:18 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_parse_flags(t_pf *pf, char **line)
{
	int		i;
	char	*tmp;

	tmp = *line;
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '#' || tmp[i] == '-' \
			|| tmp[i] == '0' || tmp[i] == '+')
	{
		if (tmp[i] == ' ')
			pf->space = 1;
		if (tmp[i] == '#' && pf->minus == 0)
			pf->hash = 1;
		if (tmp[i] == '#' && pf->minus == 1)
			pf->hash = 2;
		if (tmp[i] == '-')
			pf->minus = 1;
		if (tmp[i] == '+')
			pf->plus = 1;
		if (tmp[i] == '0')
			pf->zero = 1;
		i++;
	}
	*line = &(tmp)[i];
	return (i);
}

static void			ft_parse_width(t_pf *pf, char **line, va_list valist)
{
	char	*tmp;
	int		i;

	tmp = *line;
	if (ft_isdigit(tmp[0]))
	{
		pf->width = ft_atoi(tmp);
		tmp += ft_nbrlen(pf->width, 10);
	}
	if (tmp[0] == '*')
	{
		if ((i = va_arg(valist, int)) < 0)
		{
			pf->minus = 1;
			i = -i;
		}
		pf->width = i;
		tmp++;
	}
	if (ft_isdigit(tmp[0]))
	{
		pf->width = ft_atoi(tmp);
		tmp += ft_nbrlen(pf->width, 10);
	}
	*line = tmp;
}

static int			ft_parse_prec(t_pf *pf, char **line, va_list valist)
{
	char	*tmp;

	tmp = *line;
	if (tmp[0] != '.')
	{
		*line = tmp;
		return (0);
	}
	pf->prec = 0;
	tmp++;
	if (tmp[0] == '*')
	{
		pf->prec = va_arg(valist, int);
		tmp++;
	}
	else if (ft_isdigit(tmp[0]))
	{
		pf->prec = ft_atoi(tmp);
		tmp += ft_nbrlen(pf->prec, 10);
	}
	*line = tmp;
	return (0);
}

static int			ft_parse_length(t_pf *pf, char **line)
{
	char	*tmp;

	tmp = *line;
	if (ft_strncmp(tmp, "l", 1) == 0)
		pf->length = 3;
	if (ft_strncmp(tmp, "h", 1) == 0)
		pf->length = 4;
	if (ft_strncmp(tmp, "j", 1) == 0)
		pf->length = 5;
	if (ft_strncmp(tmp, "z", 1) == 0)
		pf->length = 6;
	if (ft_strncmp(tmp, "ll", 2) == 0)
		pf->length = 1;
	if (ft_strncmp(tmp, "hh", 2) == 0)
		pf->length = 2;
	if (pf->length > 0 && pf->length <= 2)
		tmp += 2;
	else if (pf->length > 2)
		tmp++;
	*line = tmp;
	return (1);
}

int					ft_parse_format(char **line, t_pf *pf, va_list valist)
{
	char	*tmp;

	ft_parse_flags(pf, line);
	ft_parse_width(pf, line, valist);
	ft_parse_prec(pf, line, valist);
	ft_parse_length(pf, line);
	pf->type = (*line)[0];
	(*line)++;
	if (pf->type == 'p')
	{
		pf->length = 1;
		pf->hash = 1;
	}
	if (ft_strchr("DUOCS", pf->type))
	{
		pf->length = 3;
		pf->type = ft_tolower(pf->type);
	}
	return (1);
}
