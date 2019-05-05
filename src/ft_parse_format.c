/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:48:30 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 21:23:21 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_parse_flags(t_pf *pf)
{
	char	*tmp;

	tmp = pf->form;
	while (*tmp == ' ' || *tmp == '#' || *tmp == '-' \
			 || *tmp == '0' || *tmp == '+')
	{
		if (*tmp == ' ')
			pf->space = 1;
		if (*tmp == '#')
			pf->hash = 1;
		if (*tmp == '-')
			pf->minus = 1;
		if (*tmp == '+')
			pf->plus = 1;
		if (*tmp == '0')
			pf->zero = 1;
		tmp++;
	}
	pf->form = tmp;
	return (1);
}

static int			ft_parse_width_prec(t_pf *pf)
{
	char	*tmp;

	tmp = pf->form;
	pf->width = ft_atoi(tmp);
	if (pf->width > 0)
		tmp += ft_nbrlen(pf->width, 10);	
	if (tmp[0] != '.')
		return (0);
	tmp++;
	pf->prec = ft_atoi(tmp);
	tmp += ft_nbrlen(pf->prec, 10);
	pf->form = tmp;
	return (0);
}

static int			ft_parse_length(t_pf *pf)
{
	char	*tmp;

	tmp = pf->form;
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
	return (0);
}

int					ft_parse_format(char **line, t_pf *pf)
{
	char	*tmp;

	pf->len = ft_strclen(*line, "scpdDioOuUxX%");
	pf->form = ft_strnew(pf->len);
	tmp = pf->form;
	ft_memcpy(pf->form, *line, pf->len);
	pf->type = tmp[pf->len - 1];
	ft_parse_flags(pf);	
	ft_parse_width_prec(pf);
	ft_parse_length(pf);
	if (pf->type == 'p')
	{
		pf->length = 1;
		pf->hash = 1;
	}
	if (ft_strchr("DUO", pf->type))
	{
		pf->length = 3;
		pf->type = ft_tolower(pf->type);
	}
	*line += pf->len;
	free(tmp);
	return (1);
}

