/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:48:30 by tcase             #+#    #+#             */
/*   Updated: 2019/05/12 15:16:00 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_parse_flags(t_pf *pf)
{
	int		i;
	
	i = 0;
	while (pf->form[i] == ' ' || pf->form[i] == '#' || pf->form[i] == '-' \
			|| pf->form[i] == '0' || pf->form[i] == '+')
	{
		if (pf->form[i] == ' ')
			pf->space = 1;
		if (pf->form[i] == '#')
			pf->hash = 1;
		if (pf->form[i] == '-')
			pf->minus = 1;
		if (pf->form[i] == '+')
			pf->plus = 1;
		if (pf->form[i] == '0')
			pf->zero = 1;
		i++;
	}
	pf->form = &(pf->form)[i];
	return (i);
}

static int			ft_parse_width(t_pf *pf, va_list valist)
{
	char	*tmp;
	int		i;
	int		flag;

	flag = 0;
	tmp = pf->form;
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
	pf->form = tmp;
	return (0);
}

static int			ft_parse_prec(t_pf *pf, va_list valist)
{
	char	*tmp;

	tmp = pf->form;
	if (tmp[0] != '.')
	{
		pf->form = tmp;
		return (0);
	}
	tmp++;
	if (tmp[0] == '*')
	{
		pf->prec = va_arg(valist, int);;
		tmp++;
	}
	else
	{
		pf->prec = ft_atoi(tmp);
		tmp += ft_nbrlen(pf->prec, 10);
	}
	pf->form = tmp;
	return (0);
}

static int			ft_parse_length(t_pf *pf)
{
	char	*tmp;

	tmp = pf->form;
	if ((ft_strclen(tmp, "lhjz") == 0) &&\
			(ft_strclen(tmp, "fFsScCpdDioOuUxX%") > 1))
		return (0);
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
	pf->form = tmp;
	return (1);
}

int					ft_parse_format(char **line, t_pf *pf, va_list valist)
{
	char	*tmp;

	if (!((pf->len = ft_strclen(*line, "fFsScCPpdDioOuUxX%"))))
		return (0);
	pf->form = ft_strnew(pf->len);
	tmp = pf->form;
	ft_memcpy(pf->form, *line, pf->len);
	pf->type = tmp[pf->len - 1];
	ft_parse_flags(pf);
	ft_parse_width(pf, valist);
	ft_parse_prec(pf, valist);
	if (!(ft_parse_length(pf)))
		return (0);
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
	*line += pf->len;
	return (1);
}
